#include "scMatrix3x3Array.hpp"
using namespace OPL::SimCreate;

MatrixFloat3x3Array::MatrixFloat3x3Array(string p_name) : Array(p_name, "float16")
{
}

string MatrixFloat3x3Array::getTypeName()
{
  return string("float16");
}

MatrixFloat3x3 MatrixFloat3x3Array::operator[](Int n)
{
  ostringstream variableName;
  variableName << name << "[" << n.name << "]";
  return MatrixFloat3x3(  variableName.str());
}
