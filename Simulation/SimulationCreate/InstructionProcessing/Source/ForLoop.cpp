#include "ForLoop.hpp"

namespace InsPr
{
ForLoop::ForLoop(shared_ptr<SingleInstruction> p_startInstruction,
                 shared_ptr<SingleInstruction> p_continueCondition,
                 shared_ptr<SingleInstruction> p_afterCircuitInstruction) :
    startInstruction(p_startInstruction),
    continueCondition(p_continueCondition),
    afterCircuitInstruction(p_afterCircuitInstruction),
    instructions(make_shared<InstructionBlock>())
{
}

uint ForLoop::getAlternativesCount()
{
    return startInstruction->getAlternativesCount() * 
           continueCondition->getAlternativesCount() *
           afterCircuitInstruction->getAlternativesCount() *
           instructions->getAlternativesCount();
}

void ForLoop::addInstruction(shared_ptr<IInstruction> instruction)
{
    instructions->addInstruction(instruction);
}

std::string ForLoop::getInstructionAlt(shared_ptr<SingleInstruction> instruction,
                                       uint& alternativeNb)
{
    uint altCount = instruction->getAlternativesCount();
    std::string result = instruction->getAlternative(alternativeNb % altCount);
    alternativeNb /= altCount;
    return result;
}

std::string ForLoop::getAlternative(uint alternativeNb)
{
    if ( alternativeNb >= getAlternativesCount()) 
        return std::string();

    std::ostringstream sstream; 
    sstream << "for(" << getInstructionAlt(startInstruction, alternativeNb) << "; " <<
                         getInstructionAlt(continueCondition, alternativeNb) << "; " <<
                         getInstructionAlt(afterCircuitInstruction, alternativeNb) << ")\n";

    sstream << instructions->getAlternative(alternativeNb);
    return sstream.str();
}

}

