#include "stl.hpp"
#include "sc$TypeName$LENGTH.hpp"
#include "SingleInstruction.hpp"

using namespace OPL::SimCreate;
using namespace std;

$TypeName$LENGTH::$TypeName$LENGTH() : Variable("$typename$LENGTH")
{ 
  file << "$typename$LENGTH " << this->name << ";\n";
}

$TypeName$LENGTH::$TypeName$LENGTH(string p_name) 
    : Variable(p_name,"$typename$LENGTH")
{
}

string $TypeName$LENGTH::getName()
{
  return string("$typename$LENGTH");
}
    
$TypeName$LENGTH $TypeName$LENGTH::operator=($TypeName$LENGTH rValue)
{
    std::ostringstream sstream;
    sstream << this->name << " = " << rValue.name << ";\n";
    InsPr::SingleInstruction instruction( sstream.str() );
    file << instruction.getAlternative(0);
    return *this;
}

$TypeName$LENGTH $TypeName$LENGTH::operator+($TypeName$LENGTH added)
{
  ostringstream variableName;
  variableName << " ( " << name << " + " << added.name << " ) ";
  return $TypeName$LENGTH( variableName.str());
}

$TypeName$LENGTH $TypeName$LENGTH::operator-($TypeName$LENGTH added)
{
  ostringstream variableName;
  variableName << " ( " << name << " - " << added.name << " ) ";
  return $TypeName$LENGTH( variableName.str());
}

$TypeName$LENGTH $TypeName$LENGTH::operator*($TypeName scalar)
{
  ostringstream variableName;
  variableName << " ( " << scalar.name << " * " << name << " ) ";
  return $TypeName$LENGTH( variableName.str());
}

$TypeName$LENGTH $TypeName$LENGTH::operator/($TypeName scalar)
{
  ostringstream variableName;
  variableName << " ( " << name << " / " << scalar.name << " ) ";
  return $TypeName$LENGTH( variableName.str());
}

$TypeName $TypeName$LENGTH::operator*($TypeName$LENGTH second)
{
  ostringstream variableName;
  variableName << " ( ";
  for(int i=0; i<$LENGTH; i++)
  {  
    variableName << name << ".s" << i << " * " << second.name << ".s" << i ;
    if(i < $LENGTH-1 )
      variableName << " + ";
  }
  variableName << " ) ";
  return $TypeName( variableName.str());
}

#if $LENGTH == 3
$TypeName$LENGTH $TypeName$LENGTH::operator^($TypeName$LENGTH second)
{
  simulation.addInclude("crossOperation.cl");
  ostringstream variableName;
  variableName << " $typenameCrossProduct( " << name << ", " << second.name << ") ";
  return $TypeName$LENGTH( variableName.str());
}
#endif

$TypeName$LENGTH OPL::SimCreate::operator*($TypeName scalar,$TypeName$LENGTH vector)
{
  ostringstream variableName;
  variableName << " ( " << scalar.name << " * " << vector.name << " ) ";
  return $TypeName$LENGTH( variableName.str());
}
