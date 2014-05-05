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

Float Simulation::det(Matrix4x4 m)
{
  m.simulation.addInclude("matrix_determinant.cl");
  ostringstream variableName;
  variableName << "matrix_determinant_4x4(" << m.name << ") ";
  return Float(variableName.str());
}

Float Simulation::det(Matrix3x3 m)
{
  m.simulation.addInclude("matrix_determinant.cl");
  ostringstream variableName;
  variableName << "matrix_determinant_3x3(" << m.name << ") ";
  return Float(variableName.str());
}

Matrix3x3 Simulation::invert(Matrix3x3 m)
{
  m.simulation.addInclude("matrix_invert.cl");
  ostringstream variableName;
  variableName << "invert_matrix3x3(" << m.name << ") ";
  return Matrix3x3(variableName.str());
}

void Simulation::FOR_PARALLEL( Int control_variable, Int start_value, Int end_value )
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "for( " << control_variable.name << " = " << start_value.name << "; " << 
		control_variable.name << " < " << end_value.name << "; " << 
		control_variable.name << "++ )\n";
}

void Simulation::IF_INSTRUCTION( Bool condition)
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "if( " << condition.name << " )\n";
}

void Simulation::ELSE_INSTRUCTION()
{
  ostringstream& code = CreateKernel::getCreateKernel()->getSourceCode();
  code << "else\n";  
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
