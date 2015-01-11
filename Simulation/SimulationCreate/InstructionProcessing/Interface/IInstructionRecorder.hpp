#pragma once

#include <memory>
#include <vector>
#include "IInstruction.hpp"


namespace OPL
{
namespace InsPr
{
class IInstructionBlock;
class SingleInstruction;
using std::shared_ptr;

    class IInstructionRecorder
    {
    public:
        virtual void operator<<(shared_ptr<IInstruction>) = 0;
        virtual void startBlock() = 0;
        virtual void startIf(shared_ptr<SingleInstruction>) = 0;
        virtual void startElse() = 0;
        virtual void startForLoop(shared_ptr<SingleInstruction>,
                                  shared_ptr<SingleInstruction>,
                                  shared_ptr<SingleInstruction> ) = 0;
        virtual void startWhileLoop(shared_ptr<SingleInstruction>) = 0;
        virtual void finishBlock() = 0;
        virtual shared_ptr<IInstructionBlock> getBlock() = 0;
        virtual void addInclude(std::string) = 0;
        virtual std::vector<std::string> getIncludes() = 0;
    };
}
}

