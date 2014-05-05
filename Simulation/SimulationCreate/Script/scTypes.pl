#!/usr/bin/perl

$BaseDir=$ARGV[1];

$typesListFile="$BaseDir"."/Script/types.txt";
$vecTypesFile="$BaseDir"."/Script/vec_types.txt";

$includeDir = "$BaseDir"."/Include/Types";
$sourceDir = "$BaseDir"."/Source/Types";
$objDir = "$BaseDir"."/obj/Types";

$includeVecDir = "$BaseDir"."/Include/VecTypes";
$sourceVecDir = "$BaseDir"."/Source/VecTypes";
$objVecDir = "$BaseDir"."/obj/VecTypes";

@vector_sizes = ( 2, 3, 4, 8, 16 );

sub generateTypes {
open(FILE_IN, $typesListFile);
open(FILE_TYPES, ">$includeDir/scTypes.hpp");

foreach $type (<FILE_IN>) {
    chomp($type);
    $typename = lc ( $type );
    $TypeName = ucfirst( $typename );
    
    print FILE_TYPES "#include \"sc$TypeName.hpp\"\n";
    print FILE_TYPES "#include \"sc$TypeName"."Array.hpp\"\n";
}
close(FILE_IN);

open(FILE_IN2, $vecTypesFile);
foreach $type (<FILE_IN2>) 
  {
    chomp($type);
    $typename = lc ( $type );
    $TypeName = ucfirst( $typename );
    
    for( $i=0; $i < @vector_sizes; $i++)
    {
      print FILE_TYPES "#include \"sc$TypeName$vector_sizes[$i].hpp\"\n";
      print FILE_TYPES "#include \"sc$TypeName$vector_sizes[$i]Array.hpp\"\n";
    }
  }
close(FILE_IN2);
close(FILE_TYPES);
}

sub clean {
unlink "$includeDir/scTypes.hpp";

open(FILE_IN, $typesListFile);

foreach $type (<FILE_IN>) 
  {
    chomp($type);
    $typename = lc ( $type );
    $TypeName = ucfirst( $typename );
    
    unlink "$includeDir/sc$TypeName.hpp";
    unlink "$sourceDir/sc$TypeName.cpp";
    
    unlink "$includeDir/sc$TypeName"."Array.hpp";
    unlink "$sourceDir/sc$TypeName"."Array.cpp";
  }
close(FILE_IN);

open(FILE_IN2, $vecTypesFile);
foreach $type (<FILE_IN2>) 
  {
  chomp( $type );
  $typename = lc ( $type );
  $TypeName = ucfirst( $typename );
  
  for( $i=0; $i < @vector_sizes; $i++)
    {
      unlink "$sourceVecDir/sc$TypeName$vector_sizes[$i].cpp";
      unlink "$includeVecDir/sc$TypeName$vector_sizes[$i].hpp";

      unlink "$sourceVecDir/sc$TypeName$vector_sizes[$i]"."Array.cpp";
      unlink "$includeVecDir/sc$TypeName$vector_sizes[$i]"."Array.hpp";
    }
  }  
close(FILE_IN2);
}

sub list {
open(FILE_IN, $typesListFile);
$prefix=$_[0];
$sufix=$_[1];
foreach $type (<FILE_IN>) {
    chomp($type);
    $typename = lc ( $type );
    $TypeName = ucfirst( $typename );

    print "$prefix$TypeName$sufix ";
}
close(FILE_IN);
}

sub list_vector {
open(FILE_IN2, $vecTypesFile);
$prefix=$_[0];
$sufix=$_[1];
foreach $type (<FILE_IN2>) 
  {
  chomp( $type );
  $typename = lc ( $type );
  $TypeName = ucfirst( $typename );
  
  for( $i=0; $i < @vector_sizes; $i++)
    {
      print "$prefix$TypeName$vector_sizes[$i]$sufix ";
    }
  }  
close(FILE_IN2);
}

sub list_source {
list( "$sourceDir/sc", ".cpp");
list( "$sourceDir/sc", "Array.cpp");
list_vector( "$sourceVecDir/sc",".cpp");
list_vector( "$sourceVecDir/sc","Array.cpp");
}

sub list_include {
print "$includeDir/scTypes.hpp ";
list( "$includeDir/sc", ".hpp");
list( "$includeDir/sc", "Array.hpp");
list_vector( "$includeVecDir/sc", ".hpp");
list_vector( "$includeVecDir/sc", "Array.hpp");
}

sub list_obj {
list( "$objDir/sc", ".o");
list( "$objDir/sc", "Array.o");
list_vector( "$objVecDir/sc", ".o");
list_vector( "$objVecDir/sc", "Array.o");
}

  $typename = lc( $ARGV[2] );
  $TypeName = ucfirst( $typename );
  $TYPENAME = uc( $ARGV[2] );
  
  if( $ARGV[2] =~ /(\d+)/ )
  {
    $LENGTH = $1;
    $typename =~ s/\d//g;
    $TypeName =~ s/\d//g;
    $TYPENAME =~ s/\d//g;
  }

  
$replacements = " -r TYPENAME $TYPENAME -r TypeName $TypeName -r typename $typename";
$vec_replacements = " -r TYPENAME $TYPENAME -r TypeName $TypeName -r typename $typename -r LENGTH $LENGTH";

if( $ARGV[0] eq "clean" )
{ clean(); }
elsif( $ARGV[0] eq "list_obj" )
{ list_obj(); }
elsif( $ARGV[0] eq "list_include" )
{ list_include(); }
elsif( $ARGV[0] eq "list_source" )
{ list_source(); }
elsif( $ARGV[0] eq "gen_type_include" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scType.hpp $includeDir/sc$TypeName.hpp $replacements"); }
elsif( $ARGV[0] eq "gen_type_source" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scType.cpp $sourceDir/sc$TypeName.cpp $replacements"); }
elsif( $ARGV[0] eq "gen_array_include" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scArray.hpp $includeDir/sc$TypeName"."Array.hpp $replacements"); }
elsif( $ARGV[0] eq "gen_array_source" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scArray.cpp $sourceDir/sc$TypeName"."Array.cpp $replacements"); }
elsif( $ARGV[0] eq "gen_vector_include" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scVector.hpp $includeVecDir/sc$TypeName$LENGTH.hpp $vec_replacements"); }
elsif( $ARGV[0] eq "gen_vector_source" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scVector.cpp $sourceVecDir/sc$TypeName$LENGTH.cpp $vec_replacements"); }
elsif( $ARGV[0] eq "gen_vector_array_include" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scVectorArray.hpp $includeVecDir/sc$TypeName$LENGTH"."Array.hpp $vec_replacements"); }
elsif( $ARGV[0] eq "gen_vector_array_source" )
{ exec( "$BaseDir/Script/template.sh $BaseDir/Templates/scVectorArray.cpp $sourceVecDir/sc$TypeName$LENGTH"."Array.cpp $vec_replacements"); }
elsif( $ARGV[0] eq "gen_types" )
{ generateTypes(); }
