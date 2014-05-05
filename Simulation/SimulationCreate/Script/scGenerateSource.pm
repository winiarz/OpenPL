#!/usr/bin/perl

package OplGenerateSource;
$sourceDir = "Source/Types";

sub generateTypeSource {
$typename = lc( $_[0] );
$TypeName = ucfirst( $typename );
$TYPENAME = uc ($_[0] );

$fileName="$sourceDir/Opl$TypeName.cpp";

open(FILE, ">$fileName");

print FILE "#include \"Opl$TypeName.hpp\"\n\n";

print FILE "using namespace std;\n";
print FILE "using namespace OPL;\n\n";

print FILE "  $TypeName\:\:$TypeName(fstream& p_file,string p_name)\n"; 
print FILE "       : Variable(p_file,p_name,\"$typename\")\n";
print FILE "{\n";
print FILE "}\n";
close( FILE );
}

1;
