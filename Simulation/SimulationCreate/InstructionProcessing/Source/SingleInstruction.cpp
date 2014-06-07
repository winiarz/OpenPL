#include "SingleInstruction.hpp"

namespace InsPr
{

SingleInstruction::SingleInstruction(std::string p_instruction) :
    instruction(p_instruction)
{
}

uint SingleInstruction::getAlternativesCount()
{
    return 1u;
}

std::string SingleInstruction::getAlternative(uint alternativeNb)
{
    if ( alternativeNb != 0 ) 
        return std::string();

    return instruction;
}

}

