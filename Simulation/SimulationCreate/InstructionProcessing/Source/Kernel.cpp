#include "Kernel.hpp"

namespace InsPr
{

Kernel::Kernel(std::string p_kernelName,
               std::vector<boost::shared_ptr<IGlobalArrayVariable>> p_arguments,
               boost::shared_ptr<IInstructionBlock> p_instructions) :
    kernelName(p_kernelName),
    arguments(p_arguments),
    instructions(p_instructions)
{

}

uint Kernel::getAlternativesCount()
{
    return 1;
}

std::string Kernel::getAlternative(uint alternativeNb)
{
    std::ostringstream sstream;
    sstream << "__kernel void " << kernelName << "(";

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

