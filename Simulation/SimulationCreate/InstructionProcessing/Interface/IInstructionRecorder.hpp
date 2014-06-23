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
        virtual void operator<<(std::shared_ptr<IInstruction>) = 0;
        virtual void startBlock() = 0;
        virtual void startIf(std::shared_ptr<SingleInstruction>) = 0;
        virtual void startElse() = 0;
        virtual void startForLoop(std::shared_ptr<SingleInstruction>,
                                  std::shared_ptr<SingleInstruction>,
                                  std::shared_ptr<SingleInstruction> ) = 0;
        virtual void startWhileLoop(std::shared_ptr<SingleInstruction>) = 0;
        virtual void finishBlock() = 0;
        virtual std::shared_ptr<IInstructionBlock> getBlock() = 0;
        virtual void addInclude(std::string) = 0;
        virtual std::vector<std::string> getIncludes() = 0;
    };
}

