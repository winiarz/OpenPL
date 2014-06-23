#pragma once

#include "IInstructionRecorder.hpp"

namespace InsPr
{
    class InstructionRecorder : public IInstructionRecorder
    {
    public:
        InstructionRecorder();

        virtual void operator<<(std::shared_ptr<IInstruction>);
        virtual void startBlock();
        virtual void startIf(std::shared_ptr<SingleInstruction>);
        virtual void startElse();
        virtual void startForLoop(std::shared_ptr<SingleInstruction>,
                                  std::shared_ptr<SingleInstruction>,
                                  std::shared_ptr<SingleInstruction> );
        virtual void startWhileLoop(std::shared_ptr<SingleInstruction>);
        virtual void finishBlock();
        virtual std::shared_ptr<IInstructionBlock> getBlock();

        virtual void addInclude(std::string);
        virtual std::vector<std::string> getIncludes();
    private:
        void closeBlock();
        void finishAllBlocks();
        std::stack<std::shared_ptr<IInstructionBlock>> instructionBlocks;
        std::vector<std::string> includes;
        bool shouldCloseBlock = false;
    };
}

