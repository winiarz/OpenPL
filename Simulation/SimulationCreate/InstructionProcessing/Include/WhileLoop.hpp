#pragma  once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class WhileLoop : public IInstructionBlock
    {
    public:
        WhileLoop(shared_ptr<SingleInstruction>);

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(shared_ptr<IInstruction>);
    private:
        shared_ptr<SingleInstruction> condition;
        shared_ptr<InstructionBlock> instructions;
    };
}

