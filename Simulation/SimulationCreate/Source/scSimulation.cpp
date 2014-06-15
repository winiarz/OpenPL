#include "ClPlatform.hpp"
#include "scSimulationCreate.hpp"
#include "logs.hpp"
#include "SingleInstruction.hpp"
using namespace OPL::SimCreate;

void Simulation::move(InsPr::MaterialPoint m)
{
  InsPr::IVariable::recorder->addInclude("material_point_move.cl");
  std::ostringstream sstream;
  sstream << "material_point_move ( &" << m.getName() << ",0,1,1 );\n";
  (*InsPr::IVariable::recorder) << boost::make_shared<InsPr::SingleInstruction>(sstream.str());
}

InsPr::Float Simulation::dist_sq(InsPr::MaterialPoint m1, InsPr::MaterialPoint m2)
{
  ostringstream variableName;
  variableName << "material_point_dist_sq(" << m1.getName() << ", " << m2.getName() << " ) ";
  return InsPr::Float (variableName.str() );
}

InsPr::Float Simulation::det(InsPr::MatrixFloat4x4 m)
{
  ostringstream variableName;
  variableName << "matrix4x4_determinant(" << m.getName() << ") ";
  return InsPr::Float(variableName.str());
}

InsPr::Float Simulation::det(InsPr::MatrixFloat3x3 m)
{
  ostringstream variableName;
  variableName << "matrix3x3_determinant(" << m.getName() << ") ";
  return InsPr::Float(variableName.str());
}

InsPr::MatrixFloat3x3 Simulation::invert(InsPr::MatrixFloat3x3 m)
{
  ostringstream variableName;
  variableName << "invertMatrix3x3(" << m.getName() << ") ";
  return InsPr::MatrixFloat3x3(variableName.str());
}

