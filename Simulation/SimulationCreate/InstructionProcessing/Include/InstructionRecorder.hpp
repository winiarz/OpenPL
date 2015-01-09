#pragma once

#include <stack>
#include "IInstructionRecorder.hpp"

namespace OPL
{
namespace InsPr
{
    class InstructionRecorder : public IInstructionRecorder
    {
    public:
        InstructionRecorder();

        virtual void operator<<(shared_ptr<IInstruction>);
        virtual void startBlock();
        virtual void startIf(shared_ptr<SingleInstruction>);
        virtual void startElse();
        virtual void startForLoop(shared_ptr<SingleInstruction>,
                                  shared_ptr<SingleInstruction>,
                                  shared_ptr<SingleInstruction> );
        virtual void startWhileLoop(shared_ptr<SingleInstruction>);
        virtual void finishBlock();
        virtual shared_ptr<IInstructionBlock> getBlock();

        virtual void addInclude(std::string);
        virtual std::vector<std::string> getIncludes();
    private:
        void closeBlock();
        void finishAllBlocks();
        std::stack<shared_ptr<IInstructionBlock>> instructionBlocks;
        std::vector<std::string> includes;
        bool shouldCloseBlock = false;
    };
}
}

