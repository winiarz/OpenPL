#pragma once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class IfInstruction : public IInstructionBlock
    {
    public:
        IfInstruction(std::shared_ptr<SingleInstruction>);

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(std::shared_ptr<IInstruction>);
        virtual void startElse();
    private:
        std::shared_ptr<SingleInstruction> condition;

        std::shared_ptr<InstructionBlock> instructionsForTrue;
        std::shared_ptr<InstructionBlock> instructionsForFalse;
    };
}

