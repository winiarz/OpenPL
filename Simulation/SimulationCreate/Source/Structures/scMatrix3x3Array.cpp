#include "scMatrix3x3Array.hpp"
using namespace OPL::SimCreate;

Matrix3x3Array::Matrix3x3Array(string p_name) : Array(p_name, "float16")
{
}

string Matrix3x3Array::getTypeName()
{
  return string("float16");
}

Matrix3x3 Matrix3x3Array::operator[](Int n)
{
  ostringstream variableName;
  variableName << name << "[" << n.name << "]";
  return Matrix3x3(  variableName.str());
}
