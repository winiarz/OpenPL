#pragma once

#include "boost.hpp"
#include "IInstruction.hpp"
#include "InstructionBlock.hpp"

namespace InsPr
{
    class IInstructionRecorder
    {
    public:
        virtual void operator<<(boost::shared_ptr<IInstruction>) = 0;
        virtual void startBlock() = 0;
        virtual void finishBlock() = 0;
        virtual boost::shared_ptr<InstructionBlock> getBlock() = 0;
    };
}

