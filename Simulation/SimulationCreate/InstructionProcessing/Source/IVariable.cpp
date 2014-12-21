#include "IVariable.hpp"

namespace OPL
{
namespace InsPr
{

std::vector<std::string> IVariable::getRequiredIncludes()
{
    return std::vector<std::string>();
}

void IVariable::recordAssigment( IVariable& rvalue)
{
    std::ostringstream sstream;
    sstream << getName() << " = " << rvalue.getName();
    (*recorder) << make_shared<SingleInstruction>(sstream.str());
}

std::string IVariable::getDeclaration()
{
    std::ostringstream sstream;
    sstream << getTypeName() << " " << getName();
    return sstream.str();
}

void IVariable::recordDeclaration()
{
    (*recorder) << make_shared<SingleInstruction>(getDeclaration());
}

}
}

