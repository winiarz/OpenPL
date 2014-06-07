#include "InstructionBlock.hpp"

namespace InsPr
{

void InstructionBlock::addInstruction(boost::shared_ptr<IInstruction> instruction)
{
    instructions.push_back(instruction);
}

uint InstructionBlock::getAlternativesCount()
{
    uint result = 1;
    for (auto instruction : instructions)
    {
        result *= instruction->getAlternativesCount();
    }
    return result;
}

std::string InstructionBlock::getAlternative(uint alternativeNb)
{
    if( alternativeNb >= getAlternativesCount() )
        return std::string();

    std::ostringstream sstream;
    sstream << "{\n";
    for (auto instruction : instructions)
    {
        uint instrAlternativeCount = instruction->getAlternativesCount();
        uint instrAlternativeNb = alternativeNb % instrAlternativeCount;
        sstream << instruction->getAlternative( instrAlternativeNb ) << std::endl;
        alternativeNb /= instrAlternativeCount;
    }
    sstream << "}\n";

    return sstream.str();
}

}

