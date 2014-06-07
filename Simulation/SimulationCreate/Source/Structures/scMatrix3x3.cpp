#include "stl.hpp"
#include "scMatrix3x3.hpp"
#include "SingleInstruction.hpp"
using namespace OPL::SimCreate;

Matrix3x3::Matrix3x3() : Variable("float16")
{
}

Matrix3x3::Matrix3x3(string p_name) : Variable(p_name,"float16")
{
}

Matrix3x3 Matrix3x3::operator=(Matrix3x3 rValue)
{
    std::ostringstream sstream;
    sstream << this->name << " = " << rValue.name << ";\n";
    InsPr::SingleInstruction instruction( sstream.str() );
    file << instruction.getAlternative(0);
    return *this;
}

Matrix3x3 Matrix3x3::operator+(Matrix3x3 added)
{
  ostringstream variableName;
  variableName << " ( " << name << " + " << added.name << " ) ";
  return Matrix3x3(  variableName.str());
}

Matrix3x3 Matrix3x3::operator*(Matrix3x3 added)
{
  simulation.addInclude("matrix_multiply.cl");
  ostringstream variableName;
  variableName << " matrix_multiply3x3( " << name << ", " << added.name << " ) ";
  return Matrix3x3(  variableName.str());
}

Matrix3x3 OPL::SimCreate::operator*(Float scalar,Matrix3x3 matrix)
{
  ostringstream variableName;
  variableName << " ( " << scalar.name << " * " << matrix.name << " ) ";
  return Matrix3x3(  variableName.str());
}
