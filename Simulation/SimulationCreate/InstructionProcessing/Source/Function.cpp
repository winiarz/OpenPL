#include "Function.hpp"

namespace InsPr
{

Function::Function(std::string p_functionName,
                   std::vector<shared_ptr<IVariable>> p_arguments,
                   boost::shared_ptr<InstructionBlock> p_instructions) :
    functionName(p_functionName),
    arguments(p_arguments),
    instructions(p_instructions)
{
}

uint Function::getAlternativesCount()
{
    return instructions->getAlternativesCount();
}

std::string Function::getAlternative(uint alternativeNb)
{
    std::ostringstream sstream;
    sstream << "void " << functionName << "(";

    bool isFirst = true;
    for ( auto argument : arguments) 
    {
        if ( !isFirst ) 
            sstream << ", ";
        isFirst = false;
        sstream << argument->getTypeName() << " " << argument->getName();
    }
    sstream << ")\n";
    sstream << instructions->getAlternative(alternativeNb);

    return sstream.str();
}

}

