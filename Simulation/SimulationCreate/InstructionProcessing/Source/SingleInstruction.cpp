#include "SingleInstruction.hpp"

namespace InsPr
{

SimgleInstruction::SimgleInstruction(std::string p_instruction) :
    instruction(p_instruction)
{
}

uint SimgleInstruction::getAlternativesCount()
{
    return 1u;
}

std::string SimgleInstruction::getAlternative(uint alternativeNb)
{
    if ( alternativeNb != 0 ) 
        return std::string();

    return instruction;
}

}

