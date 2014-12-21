
#include "AlternativeInstruction.hpp"
#include "logs.hpp"

namespace OPL
{
namespace InsPr
{

AlternativeInstruction::AlternativeInstruction(std::vector<std::shared_ptr<IInstruction>> p_alternatives) :
    alternatives(p_alternatives)
{
}

uint AlternativeInstruction::getAlternativesCount()
{
    uint acternativesCount = 1u;

    for (auto alternative : alternatives) 
    {
        acternativesCount += alternative->getAlternativesCount();
    }

    return acternativesCount;
}

std::string AlternativeInstruction::getAlternative(uint alternativeNb)
{
    DEBUG << "get alternative Nb: " << alternativeNb;
    if ( alternativeNb < 0 ) 
        return std::string();

    for (auto alternative : alternatives) 
    {
        if (alternativeNb < alternative->getAlternativesCount()) 
        {
            return alternative->getAlternative(alternativeNb);
        }

        alternativeNb -= alternative->getAlternativesCount();
    }

    return std::string();
}

}
}

