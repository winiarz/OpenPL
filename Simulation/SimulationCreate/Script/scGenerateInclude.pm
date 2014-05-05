#!/usr/bin/perl

package OplGenerateInclude;
$includeDir = "Include/Types";

sub generateTypeInclude {
$typename = lc( $_[0] );
$TypeName = ucfirst( $typename );
$TYPENAME = uc ($_[0] );

$fileName="$includeDir/Opl$TypeName.hpp";

open(FILE, ">$fileName");

print FILE "#ifndef __OPL_$TYPENAME"."__\n";
print FILE "#define __OPL_$TYPENAME"."__\n\n";

print FILE "#include <string>\n";
print FILE "#include <fstream>\n";

print FILE "#include \"OplVariable.hpp\"\n\n";

print FILE "namespace OPL\n\n";
print FILE "{\n";
print FILE "using namespace std;\n\n";
print FILE "class $TypeName : public Variable {\n";
print FILE "public:\n";
print FILE "  $TypeName(fstream&,string);\n";
print FILE "  virtual string getName();\n";
print FILE "};\n";

print FILE "}\n";
print FILE "#endif\n";

close( FILE ); 
}

1;