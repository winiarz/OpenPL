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

std::vector<std::string> SimgleInstruction::getAllAlternatives()
{
    std::vector<std::string> result;
    result.push_back(instruction);
    return result;
}

}

