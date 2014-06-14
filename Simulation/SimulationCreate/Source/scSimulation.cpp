#include "ClPlatform.hpp"
#include "scSimulationCreate.hpp"
#include "scTypes.hpp"
#include "logs.hpp"
using namespace OPL::SimCreate;

void Simulation::move(MaterialPoint m)
{
  m.simulation.addInclude("material_point_move.cl");
  m.file << "material_point_move ( &" << m.name << ",0,1,1 );\n";
}

void Simulation::move(MaterialPointArray& m,int start,int end)
{
  m.simulation.addInclude("material_point_move.cl");
  m.file << "material_point_move ( " << m.name << "," << start << "+get_global_id(0)," << end << "," << " get_global_size(0));\n";
}

Float Simulation::dist_sq(MaterialPoint m1, MaterialPoint m2)
{
  ostringstream variableName;
  variableName << "material_point_dist_sq(" << m1.name << ", " << m2.name << " ) ";
  return Float (variableName.str() );
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

void Simulation::FOR_PARALLEL( Int control_variable, Int start_value, Int end_value )
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "for( " << control_variable.name << " = " << start_value.name << "; " << 
		control_variable.name << " < " << end_value.name << "; " << 
		control_variable.name << "++ )\n";
}

void Simulation::WHILE_INSTRUCTION( Bool condition )
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "while( " << condition.name << " )\n";  
}

void Simulation::print_opening_brace()
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "{\n";
}

void Simulation::print_closing_brace()
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "}\n";
}
