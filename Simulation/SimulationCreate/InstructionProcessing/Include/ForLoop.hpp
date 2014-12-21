#pragma once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace OPL
{
namespace InsPr
{
    class ForLoop : public IInstructionBlock
    {
    public:
        ForLoop(shared_ptr<SingleInstruction>,
                shared_ptr<SingleInstruction>,
                shared_ptr<SingleInstruction> );

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(shared_ptr<IInstruction>);
    private:
        std::string getInstructionAlt(shared_ptr<SingleInstruction> instruction,
                                      uint&);

        shared_ptr<SingleInstruction> startInstruction;
        shared_ptr<SingleInstruction> continueCondition;
        shared_ptr<SingleInstruction> afterCircuitInstruction;

        shared_ptr<InstructionBlock> instructions;
    };
}
}

