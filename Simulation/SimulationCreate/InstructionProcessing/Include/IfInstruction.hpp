#pragma once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace OPL
{
namespace InsPr
{
    class IfInstruction : public IInstructionBlock
    {
    public:
        IfInstruction(shared_ptr<SingleInstruction>);

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(shared_ptr<IInstruction>);
        virtual void startElse();
    private:
        shared_ptr<SingleInstruction> condition;

        shared_ptr<InstructionBlock> instructionsForTrue;
        shared_ptr<InstructionBlock> instructionsForFalse;
    };
}
}

