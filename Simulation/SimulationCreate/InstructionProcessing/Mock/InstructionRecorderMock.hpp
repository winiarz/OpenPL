#pragma once

#include <gmock/gmock.h>
#include "IInstructionRecorder.hpp"

namespace InsPr
{
    class InstructionRecorderMock : public IInstructionRecorder
    {
    public:
        MOCK_METHOD1( operator_ii, void (boost::shared_ptr<IInstruction>) );
        virtual void operator<<(boost::shared_ptr<IInstruction> instruction)
        {
            operator_ii(instruction);
        }
        MOCK_METHOD0( startBlock, void () );
        MOCK_METHOD1( startIf, void (boost::shared_ptr<SingleInstruction>) );
        MOCK_METHOD0( startElse, void() );
        MOCK_METHOD3( startForLoop, void (boost::shared_ptr<SingleInstruction>,
                                          boost::shared_ptr<SingleInstruction>,
                                          boost::shared_ptr<SingleInstruction> ) );
        MOCK_METHOD1( startWhileLoop, void (boost::shared_ptr<SingleInstruction>) );
        MOCK_METHOD0( finishBlock, void() );
        MOCK_METHOD0( getBlock, boost::shared_ptr<IInstructionBlock>() );
    };

}

