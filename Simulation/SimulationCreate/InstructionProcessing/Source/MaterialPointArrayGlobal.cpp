#include "MaterialPointArrayGlobal.hpp"

namespace InsPr
{

void MaterialPointArrayGlobal::move()
{
    InsPr::IVariable::recorder->addInclude("material_point_move.cl");
    std::ostringstream sstream;
    sstream << "material_point_move ( " << array.getName() << ",0, " << size.getName() << "[0],1 );\n";
    (*recorder) << make_shared<InsPr::SingleInstruction>(sstream.str());
}

void MaterialPointArrayGlobal::setForce(Float4 force)
{
    IVariable::recorder->addInclude("material_point_move.cl");
    std::ostringstream sstream;
    sstream << "material_point_apply_force ( " << array.getName() << ", " << size.getName() << "[0], " << force.getName() << ");\n";
    (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
}

void MaterialPointArrayGlobal::clearForce()
{
    std::ostringstream sstream;
    sstream << "material_point_apply_force ( " << array.getName() << ", " << size.getName() << "[0], (float4)0 );\n";
    (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
}

void MaterialPointArrayGlobal::applyForcesOfGravity(Float gravityConstant)
{
    IVariable::recorder->addInclude("material_point_nbody.cl");
    std::ostringstream sstream;
    sstream << "material_point_apply_forces_of_gravity ( " << array.getName() << ", " << size.getName() << "[0], " << gravityConstant.getName() << ");";
    (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
}

}

