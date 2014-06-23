#pragma once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class ForLoop : public IInstructionBlock
    {
    public:
        ForLoop(std::shared_ptr<SingleInstruction>,
                std::shared_ptr<SingleInstruction>,
                std::shared_ptr<SingleInstruction> );

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(std::shared_ptr<IInstruction>);
    private:
        std::string getInstructionAlt(std::shared_ptr<SingleInstruction> instruction,
                                      uint&);

        std::shared_ptr<SingleInstruction> startInstruction;
        std::shared_ptr<SingleInstruction> continueCondition;
        std::shared_ptr<SingleInstruction> afterCircuitInstruction;

        std::shared_ptr<InstructionBlock> instructions;
    };
}

