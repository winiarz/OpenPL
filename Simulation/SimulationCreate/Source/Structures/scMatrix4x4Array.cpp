#include "scMatrix4x4Array.hpp"
using namespace OPL::SimCreate;

MatrixFloat4x4Array::MatrixFloat4x4Array(string p_name) : Array(p_name, "float16")
{
}

string MatrixFloat4x4Array::getTypeName()
{
  return string("float16");
}

MatrixFloat4x4 MatrixFloat4x4Array::operator[](Int n)
{
  ostringstream variableName;
  variableName << name << "[" << n.name << "]";
  return MatrixFloat4x4(  variableName.str());
}
