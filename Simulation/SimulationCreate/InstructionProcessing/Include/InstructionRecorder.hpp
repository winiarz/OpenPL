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
        virtual void startIf(boost::shared_ptr<SingleInstruction>);
        virtual void startElse();
        virtual void startForLoop(boost::shared_ptr<SingleInstruction>,
                                  boost::shared_ptr<SingleInstruction>,
                                  boost::shared_ptr<SingleInstruction> );
        virtual void startWhileLoop(boost::shared_ptr<SingleInstruction>);
        virtual void finishBlock();
        virtual boost::shared_ptr<IInstructionBlock> getBlock();

        virtual void addInclude(std::string);
        virtual std::vector<std::string> getIncludes();
    private:
        void finishAllBlocks();
        std::stack<boost::shared_ptr<IInstructionBlock>> instructionBlocks;
        std::vector<std::string> includes;
    };
}

