#pragma  once

#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class WhileLoop : public IInstructionBlock
    {
    public:
        WhileLoop(boost::shared_ptr<SingleInstruction>);

        virtual uint getAlternativesCount();
        virtual std::string getAlternative(uint);
        virtual void addInstruction(boost::shared_ptr<IInstruction>);
    private:
        boost::shared_ptr<SingleInstruction> condition;
        boost::shared_ptr<InstructionBlock> instructions;
    };
}

