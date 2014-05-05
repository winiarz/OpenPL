#include "scMatrix4x4Array.hpp"
using namespace OPL::SimCreate;

Matrix4x4Array::Matrix4x4Array(string p_name) : Array(p_name, "float16")
{
}

string Matrix4x4Array::getTypeName()
{
  return string("float16");
}

Matrix4x4 Matrix4x4Array::operator[](Int n)
{
  ostringstream variableName;
  variableName << name << "[" << n.name << "]";
  return Matrix4x4(  variableName.str());
}
