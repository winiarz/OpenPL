#include "scMaterialPointArray.hpp"
using namespace OPL::SimCreate;
using namespace std;

MaterialPointArray::MaterialPointArray( string p_name)
      : Array(p_name,getTypeName())
{
  simulation.addInclude("material_point.cl");
}

string MaterialPointArray::getTypeName()
{
  return string("struct MaterialPoint");
}

MaterialPoint MaterialPointArray::operator[](int n)
{
  ostringstream variableName;
  variableName << name << "[" << n << "]";
  return MaterialPoint( variableName.str());
}
