#include "stl.hpp"
#include "scMaterialPoint.hpp"
#include "SingleInstruction.hpp"
using namespace OPL::SimCreate;
using namespace std;

MaterialPoint::MaterialPoint(string p_name)
  : Variable(p_name,"struct MaterialPoint"), position("position"), speed("speed"), force("force"), mass("mass"), nothing("nothing")
{
  
}

MaterialPoint MaterialPoint::operator=(MaterialPoint rValue)
{
    std::ostringstream sstream;
    sstream << this->name << " = " << rValue.name << ";\n";
    InsPr::SingleInstruction instruction( sstream.str() );
    file << instruction.getAlternative(0);
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
