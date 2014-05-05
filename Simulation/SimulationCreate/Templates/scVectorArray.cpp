#include "sc$TypeName$LENGTHArray.hpp"

using namespace std;
using namespace OPL::SimCreate;

$TypeName$LENGTHArray::$TypeName$LENGTHArray(string p_name)
       : Array(p_name,"$typename$LENGTH")
{
}

string $TypeName$LENGTHArray::getTypeName()
{
  return "$typename$LENGTH";
}

$TypeName$LENGTH $TypeName$LENGTHArray::operator[](int n)
{
  ostringstream variableName;
  variableName << name << "[" << n << "]";
  return $TypeName$LENGTH( variableName.str());
}
