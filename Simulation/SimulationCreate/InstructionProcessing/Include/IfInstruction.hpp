#pragma once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class IfInstruction : public IInstructionBlock
    {
    public:
        IfInstruction(boost::shared_ptr<SingleInstruction>);

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(boost::shared_ptr<IInstruction>);
        virtual void startElse();
    private:
        boost::shared_ptr<SingleInstruction> condition;

        boost::shared_ptr<InstructionBlock> instructionsForTrue;
        boost::shared_ptr<InstructionBlock> instructionsForFalse;
    };
}

