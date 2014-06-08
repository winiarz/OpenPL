#pragma once

#include "boost.hpp"
#include "IInstruction.hpp"
#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"

namespace InsPr
{
    class IInstructionRecorder
    {
    public:
        virtual void operator<<(boost::shared_ptr<IInstruction>) = 0;
        virtual void startBlock() = 0;
        virtual void startIf(boost::shared_ptr<SingleInstruction>) = 0;
        virtual void startElse() = 0;
        virtual void startForLoop(boost::shared_ptr<SingleInstruction>,
                                  boost::shared_ptr<SingleInstruction>,
                                  boost::shared_ptr<SingleInstruction> ) = 0;
        virtual void startWhileLoop(boost::shared_ptr<SingleInstruction>) = 0;
        virtual void finishBlock() = 0;
        virtual boost::shared_ptr<IInstructionBlock> getBlock() = 0;
    };
}

