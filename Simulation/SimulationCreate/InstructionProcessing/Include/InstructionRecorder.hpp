#pragma once

#include "IInstructionRecorder.hpp"

namespace InsPr
{
    class InstructionRecorder : public IInstructionRecorder
    {
    public:
        InstructionRecorder();

        virtual void operator<<(boost::shared_ptr<IInstruction>);
        virtual void startBlock();
        virtual void startForLoop(boost::shared_ptr<SingleInstruction>,
                                  boost::shared_ptr<SingleInstruction>,
                                  boost::shared_ptr<SingleInstruction> );
        virtual void finishBlock();
        virtual boost::shared_ptr<IInstructionBlock> getBlock();
    private:
        void finishAllBlocks();
        std::stack<boost::shared_ptr<IInstructionBlock>> instructionBlocks;
    };
}

