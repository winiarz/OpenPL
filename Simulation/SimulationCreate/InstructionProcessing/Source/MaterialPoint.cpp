#include "MaterialPoint.hpp"

namespace InsPr
{

MaterialPoint::MaterialPoint() :
    IVariable()
{
}

MaterialPoint::MaterialPoint(std::string p_name) :
    name(p_name)
{
}

std::string MaterialPoint::getName()
{
    return name;
}

std::string MaterialPoint::getTypeName()
{
    return "struct MaterialPoint";
}

std::vector<std::string> MaterialPoint::getRequiredIncludes()
{
    std::vector<std::string> result;
    result.push_back("material_point.cl");
    return result;
}
    
MaterialPoint MaterialPoint::operator=( MaterialPoint rvalue )
{
    recordAssigment(rvalue);
    return *this;
}

MaterialPoint MaterialPoint::operator<< ( Float3 force )
{
    std::ostringstream sstream;
    sstream << getName() << ".force += (float4)(" << force.getName() << ",0)";
    (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
    return *this;
}

void MaterialPoint::move()
{
    IVariable::recorder->addInclude("material_point_move.cl");
    std::ostringstream sstream;
    sstream << "material_point_move ( &" << getName() << ",0,1,1 );\n";
    (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
}

void MaterialPoint::setForce(Float4 force)
{
    IVariable::recorder->addInclude("material_point_move.cl");
    std::ostringstream sstream;
    sstream << "material_point_apply_force ( " << getName() << ", " << 1 << ", " << force.getName() << ");\n";
    (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
}

}
