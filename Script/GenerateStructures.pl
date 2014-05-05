#!/usr/bin/perl

use XML::DOM;

$clinclude = "clinclude";
$simulation_create_include = "Simulation/SimulationCreate/Include/Structures";
$simulation_execute_include = "Simulation/SimulationExecute/Include/Structures";
$testDirectory = "AutoTest";

$structures_filename = $ARGV[0];

my $parser = new XML::DOM::Parser;
my $doc = $parser->parsefile ($structures_filename);
my $nodes = $doc->getElementsByTagName ("STRUCT");
my $length = $nodes->getLength;

for( $i=0; $i<$length; $i++)
  {
    my $node = $nodes->item( $i );
    my $structure_name = $node->getAttribute("name");
    
    simulation_execute_hpp($node,"OplLocal$structure_name.hpp");
    simulation_create_hpp($node,"Opl$structure_name.hpp");
    simulation_test_include($node,"MySim.hpp");
    simulation_test_source($node,"MySim.cpp");
    simulation_test_main($node,"main.cpp");
  }

sub opencl_structure {
  $node = $_[0];
  $filename = $_[1];
  
  open( FILE, ">$simulation_execute_include/$filename" );
  
  $name = $node->getAttribute("name");
  $NAME = uc($name);
  
  print FILE "struct Local$name {\n";
  
  for my $field ( $node->getChildNodes )
  {
    if( $field->getNodeType == ELEMENT_NODE )
    { 
      $field_name = $field->getAttribute("name");
      $field_type = $field->getAttribute("type");
      $field_size = $field->getAttribute("size");
      if( $field_size )
      {
	print FILE "$field_type $field_name\[$field_size\];\n";
      }
      else
      {
        print FILE "$field_type $field_name;\n";
      }
    }
  }
  print FILE "};\n";
  
  close( FILE );
}
  
sub simulation_execute_hpp {
  $node = $_[0];
  $filename = $_[1];
  
  open( FILE, ">$simulation_execute_include/$filename" );
  
  $name = $node->getAttribute("name");
  $NAME = uc($name);
  $ifndef = "__OPL_LOCAL_$NAME"."__";
  
  print FILE "#ifndef $ifndef\n";
  print FILE "#define $ifndef\n";
  print FILE "#include \"OplTypes.hpp\"\n\n";
  
  print FILE "namespace OPL\n";
  print FILE "{\n";
  print FILE "class Local$name {\n";
  print FILE "public:\n";
  
  for my $field ( $node->getChildNodes )
  {
    if( $field->getNodeType == ELEMENT_NODE )
    { 
      $field_name = $field->getAttribute("name");
      $field_type = $field->getAttribute("type");
      $field_size = $field->getAttribute("size");
      if( $field_size )
      {
	print FILE "Local$field_type $field_name\[$field_size\];\n";
      }
      else
      {
        print FILE "Local$field_type $field_name;\n";
      }
    }
  }
  print FILE "bool operator==( Local$name& );\n";
  print FILE "};\n";
  print FILE "}\n";
  print FILE "#endif\n";
  
  close( FILE );
}

sub simulation_create_hpp {
  $node = $_[0];
  $filename = $_[1];
  
  open( FILE, ">$simulation_create_include/$filename" );
  
  $name = $node->getAttribute("name");
  $NAME = uc($name);
  $ifndef = "__OPL_$NAME"."__";
  
  print FILE "#ifndef $ifndef\n";
  print FILE "#define $ifndef\n";
  
  print FILE "#include \"OplTypes.hpp\"\n";
  print FILE "#include \"OplVariable.hpp\"\n";
  
  print FILE "namespace OPL\n";
  print FILE "{\n";
  
  print FILE "class $name : public Variable {\n";
  print FILE "public:\n";
  
  for my $field ( $node->getChildNodes )
  {
    if( $field->getNodeType == ELEMENT_NODE )
    { 
      $field_name = $field->getAttribute("name");
      $field_type = $field->getAttribute("type");
      $field_size = $field->getAttribute("size");
      if( $field_size )
      {
	print FILE "$field_type"."Array $field_name;\n";
      }
      else
      {
        print FILE "$field_type $field_name;\n";
      }
    }
  }
  
  print FILE "$name(string);\n";
  print FILE "$name operator=($name);\n";
  print FILE "static string getTypeName();\n";
  
  print FILE "};\n";
  print FILE "}\n";
  
  print FILE "#endif\n";
  
  close( FILE );
}

sub fields_count {
  $node = $_[0];
  $field_count = 0;
  for my $field ( $node->getChildNodes )
  {
    if( $field->getNodeType == ELEMENT_NODE )
    { $field_count++; }
  }
  return $field_count;  
}

sub simulation_test_include {
  $node = $_[0];
  $filename = $_[1];
  
  open( FILE, ">$testDirectory/$name/$filename" );
  
  $name = $node->getAttribute("name");
  $field_count = fields_count($node) + 1;
  print FILE "#include \"Simulation.hpp\"\n";
  print FILE "using namespace OPL;\n";
  print FILE "class MySim : public Simulation {\n";
  print FILE "public:\n";
  print FILE "MEMORY( $name"."Array, example, 1);\n";
  print FILE "MEMORY( IntArray, offsets, $field_count);\n";
  print FILE "KERNEL_DEF2( get_offsets, $name"."Array, IntArray);\n";
  print FILE "};\n";
  
  
  close( FILE );
}

sub simulation_test_source {
  $node = $_[0];
  $filename = $_[1];
  
  open( FILE, ">$testDirectory/$name/$filename" );
  
  $name = $node->getAttribute("name");
  
  print FILE "#include \"MySim.hpp\"\n\n";
  print FILE "KERNEL_IMP2( MySim, get_offsets, $name"."Array, example, IntArray, offsets,\n";
  print FILE "{\n";
  
  $i = 0;
  for my $field ( $node->getChildNodes )
  {
    if( $field->getNodeType == ELEMENT_NODE )
    { 
      $field_name = $field->getAttribute("name");
      
      print FILE "offsets[$i] = OffsetOf<$name>(example[0],\"$field_name\");\n";
      $i++;
    }
  }  
  print FILE "offsets[$i] = SizeOf<$name>();\n";
  print FILE "})\n";

  close( FILE );
}

sub simulation_test_main {
  $node = $_[0];
  $filename = $_[1];
  
  open( FILE, ">$testDirectory/$name/$filename" );
  
  $name = $node->getAttribute("name");
  $testSuite = "$name"."TS";
  $field_count = fields_count($node)+1;
  
  print FILE "#include <gtest/gtest.h>\n";
  print FILE "#include <iostream>\n";
  print FILE "using namespace std;\n";
  print FILE "#include \"MySim.hpp\"\n\n";
  
  print FILE "class $testSuite : public ::testing::Test {\n";
  print FILE "protected:\n";
  print FILE "MySim sim;\n";
  print FILE "};\n\n";
  
  print FILE "TEST_F( $testSuite, test_offsets )\n";
  print FILE "{\n";
  
  print FILE "int loc_offsets[$field_count];\n";
  print FILE "sim.get_offsets( sim.example, sim.offsets );\n";
  print FILE "sim.offsets.copyOut( loc_offsets, 0, $field_count);\n";

  
  
  $i = 0;
  for my $field ( $node->getChildNodes )
  {
    if( $field->getNodeType == ELEMENT_NODE )
    { 
      $field_name = $field->getAttribute("name");
      print FILE "ASSERT_EQ( offsetof( Local$name, $field_name), loc_offsets[$i] );\n";
      
      $i++;
    }
  }  
  print FILE "ASSERT_EQ( sizeof( Local$name ), loc_offsets[$i] );\n";
  print FILE "}\n";
  
  close( FILE );
}
