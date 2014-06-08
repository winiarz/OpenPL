#pragma once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class ForLoop : public IInstructionBlock
    {
    public:
        ForLoop(boost::shared_ptr<SingleInstruction>,
                boost::shared_ptr<SingleInstruction>,
                boost::shared_ptr<SingleInstruction> );

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(boost::shared_ptr<IInstruction>);
    private:
        std::string getInstructionAlt(boost::shared_ptr<SingleInstruction> instruction,
                                      uint&);

        boost::shared_ptr<SingleInstruction> startInstruction;
        boost::shared_ptr<SingleInstruction> continueCondition;
        boost::shared_ptr<SingleInstruction> afterCircuitInstruction;

        boost::shared_ptr<InstructionBlock> instructions;
    };
}

