#!/usr/bin/perl

package OplGenerateTableInclude;
$includeDir = "Include/Types";

sub generateTableInclude {
$typename = lc( $_[0] );
$TypeName = ucfirst( $typename );
$TYPENAME = uc ($_[0] );

$tabletypename = "$typename"."table";
$TableTypeName = "$TypeName"."Table";
$TABLETYPENAME = "$TYPENAME"."_TABLE";

$fileName="$includeDir/Opl$TableTypeName.hpp";

open(FILE, ">$fileName");

print FILE "#ifndef __OPL_$TABLETYPENAME"."__\n";
print FILE "#define __OPL_$TABLETYPENAME"."__\n\n";

print FILE "#include \"OplTable.hpp\"\n";
print FILE "#include \"Opl$TypeName.hpp\"\n";

print FILE "namespace OPL\n\n";
print FILE "{\n";
print FILE "using namespace std;\n\n";
print FILE "class $TableTypeName : public Table {\n";
print FILE "public:\n";
print FILE "  $TableTypeName(fstream&,string);\n";
#print FILE "  virtual string getName();\n";
print FILE "};\n";

print FILE "}\n";
print FILE "#endif\n";

close( FILE ); 
}

1;