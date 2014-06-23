#pragma once

#include <gmock/gmock.h>
#include "IInstructionRecorder.hpp"

namespace InsPr
{
    class InstructionRecorderMock : public IInstructionRecorder
    {
    public:
        MOCK_METHOD1( operator_ii, void (std::shared_ptr<IInstruction>) );
        virtual void operator<<(std::shared_ptr<IInstruction> instruction)
        {
            operator_ii(instruction);
        }
        MOCK_METHOD0( startBlock, void () );
        MOCK_METHOD1( startIf, void (std::shared_ptr<SingleInstruction>) );
        MOCK_METHOD0( startElse, void() );
        MOCK_METHOD3( startForLoop, void (std::shared_ptr<SingleInstruction>,
                                          std::shared_ptr<SingleInstruction>,
                                          std::shared_ptr<SingleInstruction> ) );
        MOCK_METHOD1( startWhileLoop, void (std::shared_ptr<SingleInstruction>) );
        MOCK_METHOD0( finishBlock, void() );
        MOCK_METHOD0( getBlock, std::shared_ptr<IInstructionBlock>() );

        MOCK_METHOD1( addInclude, void(std::string) );
        MOCK_METHOD0( getIncludes, std::vector<std::string>() );
    };

}

