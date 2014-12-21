#include "WhileLoop.hpp"

namespace OPL
{
namespace InsPr
{

WhileLoop::WhileLoop(shared_ptr<SingleInstruction> p_condition) :
    condition(p_condition),
    instructions(make_shared<InstructionBlock>())
{
}

uint WhileLoop::getAlternativesCount()
{
    return condition->getAlternativesCount() *
           instructions->getAlternativesCount();
}

std::string WhileLoop::getAlternative(uint alternativeNb)
{
    std::ostringstream sstream;
    sstream << "while( " << condition->getAlternative(alternativeNb % condition->getAlternativesCount()) << " )\n";
    alternativeNb /= condition->getAlternativesCount();
    sstream << instructions->getAlternative(alternativeNb);
    return sstream.str();
}

void WhileLoop::addInstruction(shared_ptr<IInstruction> instruction)
{
    instructions->addInstruction(instruction);
}

}
}

