#include "stl.hpp"
#include "sc$TypeName.hpp"
#include "SingleInstruction.hpp"

using namespace std;
using namespace OPL::SimCreate;

$TypeName::$TypeName() : Variable( "$typename")
{
  file << "$typename " << this->name << ";\n";
}

  $TypeName::$TypeName(string p_name)
       : Variable(p_name,"$typename")
{
}

string $TypeName::getName()
{
    return string("$typename");
}

$TypeName $TypeName::operator=($TypeName rValue)
{
    std::ostringstream sstream;
    sstream << this->name << " = " << rValue.name;
    boost::shared_ptr<InsPr::SingleInstruction> instruction = boost::make_shared<InsPr::SingleInstruction>( sstream.str() );
    sstream << ";\n";
    file << sstream.str();
    (*recorder) << instruction;
    return *this;
}

$TypeName $TypeName::operator+($TypeName added)
{
  ostringstream variableName;
  variableName << " ( " << name << " + " << added.name << " ) ";
  return $TypeName(variableName.str());
}

$TypeName $TypeName::operator-($TypeName added)
{
  ostringstream variableName;
  variableName << " ( " << name << " - " << added.name << " ) ";
  return $TypeName(variableName.str());
}

$TypeName $TypeName::operator*($TypeName added)
{
  ostringstream variableName;
  variableName << " ( " << name << " * " << added.name << " ) ";
  return $TypeName( variableName.str());
}

$TypeName $TypeName::operator/($TypeName added)
{
  ostringstream variableName;
  variableName << " ( " << name << " / " << added.name << " ) ";
  return $TypeName(variableName.str());
}

$TypeName $TypeName::operator%($TypeName added)
{
  ostringstream variableName;
  variableName << " ( " << name << " % " << added.name << " ) ";
  return $TypeName(variableName.str());
}

$TypeName::$TypeName( $typename constant )
  : Variable("$typename")
{
  file << getName() << " " << this->name << " = " << constant << ";\n";
}

Bool $TypeName::operator<($TypeName rValue)
{
  ostringstream variableName;
  variableName << " ( " << name << " < " << rValue.name << " ) ";
  return Bool( variableName.str());
}

Bool $TypeName::operator>($TypeName rValue)
{
  ostringstream variableName;
  variableName << " ( " << name << " > " << rValue.name << " ) ";
  return Bool( variableName.str());
}

Bool $TypeName::operator<=($TypeName rValue)
{
  ostringstream variableName;
  variableName << " ( " << name << " <= " << rValue.name << " ) ";
  return Bool( variableName.str());
}

Bool $TypeName::operator>=($TypeName rValue)
{
  ostringstream variableName;
  variableName << " ( " << name << " >= " << rValue.name << " ) ";
  return Bool( variableName.str());
}
