#include "sc$TypeNameArray.hpp"

using namespace std;
using namespace OPL::SimCreate;

$TypeNameArray::$TypeNameArray(string p_name)
    : Array(p_name,"$typename")
{
}

string $TypeNameArray::getTypeName()
{
  return string("$typename");
}

$TypeName $TypeNameArray::operator[](int n)
{
  ostringstream variableName;
  variableName << name << "[" << n << "]";
  return $TypeName(  variableName.str());
}
