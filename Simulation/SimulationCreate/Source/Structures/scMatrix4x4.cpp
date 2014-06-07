#include "stl.hpp"
#include "scMatrix4x4.hpp"
#include "SingleInstruction.hpp"
using namespace OPL::SimCreate;

Matrix4x4::Matrix4x4() : Variable("float16")
{
}

Matrix4x4::Matrix4x4(string p_name) : Variable(p_name,"float16")
{
}

Matrix4x4 Matrix4x4::operator=(Matrix4x4 rValue)
{
    std::ostringstream sstream;
    sstream << this->name << " = " << rValue.name << ";\n";
    InsPr::SingleInstruction instruction( sstream.str() );
    file << instruction.getAlternative(0);
    return *this;
}

Matrix4x4 Matrix4x4::operator+(Matrix4x4 added)
{
  ostringstream variableName;
  variableName << " ( " << name << " + " << added.name << " ) ";
  return Matrix4x4(  variableName.str());
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 added)
{
  simulation.addInclude("matrix_multiply.cl");
  ostringstream variableName;
  variableName << " matrix_multiply4x4( " << name << ", " << added.name << " ) ";
  return Matrix4x4(  variableName.str());
}

Matrix4x4 OPL::SimCreate::operator*(Float scalar,Matrix4x4 matrix)
{
  ostringstream variableName;
  variableName << " ( " << scalar.name << " * " << matrix.name << " ) ";
  return Matrix4x4(  variableName.str());
}
