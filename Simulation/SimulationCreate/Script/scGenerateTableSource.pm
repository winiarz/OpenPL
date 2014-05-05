#!/usr/bin/perl

package OplGenerateTableSource;
$sourceDir = "Source/Types";

sub generateTableSource {
$typename = lc( $_[0] );
$TypeName = ucfirst( $typename );
$TYPENAME = uc ($_[0] );

$tabletypename = "$typename"."table";
$TableTypeName = "$TypeName"."Table";
$TABLETYPENAME = "$TYPENAME"."_TABLE";

$fileName="$sourceDir/Opl$TableTypeName.cpp";

open(FILE, ">$fileName");

print FILE "#include \"OplTable.hpp\"\n";
print FILE "#include \"Opl$TableTypeName.hpp\"\n\n";

print FILE "using namespace std;\n";
print FILE "using namespace OPL;\n\n";

print FILE "  $TableTypeName\:\:$TableTypeName(fstream& p_file,string p_name)\n"; 
print FILE "       : Table(p_file,p_name,\"$typename\")\n";
print FILE "{\n";
print FILE "}\n";
close( FILE );
}

1;
