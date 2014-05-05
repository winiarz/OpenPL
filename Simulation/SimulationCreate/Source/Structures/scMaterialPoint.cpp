#include "scMaterialPoint.hpp"
using namespace OPL::SimCreate;
using namespace std;

MaterialPoint::MaterialPoint(string p_name)
  : Variable(p_name,"struct MaterialPoint"), position("position"), speed("speed"), force("force"), mass("mass"), nothing("nothing")
{
  
}

MaterialPoint MaterialPoint::operator=(MaterialPoint rValue)
{
  file << this->name << " = " << rValue.name << ";\n";
  return *this;
}

string MaterialPoint::getTypeName()
{
  return string("struct MaterialPoint");
}

MaterialPoint MaterialPoint::operator<<(Float3 force)
{
  file << this->name << ".force += (float4)(" << force.name << ",0);\n";
  return *this;
}
