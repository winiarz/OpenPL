#include "IfInstruction.hpp"

namespace InsPr
{
IfInstruction::IfInstruction(std::shared_ptr<SingleInstruction> p_condition) :
    condition(p_condition),
    instructionsForTrue(std::make_shared<InstructionBlock>()),
    instructionsForFalse(std::shared_ptr<InstructionBlock>())
{
}

uint IfInstruction::getAlternativesCount()
{
    uint result = condition->getAlternativesCount() *
                  instructionsForTrue->getAlternativesCount();
    if (instructionsForFalse) 
        result *= instructionsForFalse->getAlternativesCount();
    return result;
}

std::string IfInstruction::getAlternative(uint alternativeNb)
{
    std::ostringstream sstream;
    sstream << "if( " << condition->getAlternative(alternativeNb % condition->getAlternativesCount()) << " )\n";

    uint instructionsForTrueAltCount = instructionsForTrue->getAlternativesCount();
    sstream << instructionsForTrue->getAlternative( alternativeNb % instructionsForTrueAltCount );
    alternativeNb /= instructionsForTrueAltCount;

    if ( instructionsForFalse ) 
    {
        sstream << "else\n" << instructionsForFalse->getAlternative(alternativeNb);
    }

    return sstream.str();
}

void IfInstruction::addInstruction(std::shared_ptr<IInstruction> instruction)
{
    if ( instructionsForFalse ) 
        instructionsForFalse->addInstruction(instruction);
    else
        instructionsForTrue->addInstruction(instruction);
}

void IfInstruction::startElse()
{
    instructionsForFalse = std::make_shared<InstructionBlock>();
}

}

