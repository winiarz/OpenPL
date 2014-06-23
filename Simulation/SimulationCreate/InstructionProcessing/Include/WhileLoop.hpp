#pragma  once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class WhileLoop : public IInstructionBlock
    {
    public:
        WhileLoop(std::shared_ptr<SingleInstruction>);

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(std::shared_ptr<IInstruction>);
    private:
        std::shared_ptr<SingleInstruction> condition;
        std::shared_ptr<InstructionBlock> instructions;
    };
}

