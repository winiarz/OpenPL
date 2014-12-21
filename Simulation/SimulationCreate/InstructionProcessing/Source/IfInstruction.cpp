#include "IfInstruction.hpp"

namespace OPL
{
namespace InsPr
{

IfInstruction::IfInstruction(shared_ptr<SingleInstruction> p_condition) :
    condition(p_condition),
    instructionsForTrue(make_shared<InstructionBlock>()),
    instructionsForFalse(shared_ptr<InstructionBlock>())
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

void IfInstruction::addInstruction(shared_ptr<IInstruction> instruction)
{
    if ( instructionsForFalse ) 
        instructionsForFalse->addInstruction(instruction);
    else
        instructionsForTrue->addInstruction(instruction);
}

void IfInstruction::startElse()
{
    instructionsForFalse = make_shared<InstructionBlock>();
}

}
}

