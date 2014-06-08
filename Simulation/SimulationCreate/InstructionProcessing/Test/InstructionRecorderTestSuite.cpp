#include <gtest/gtest.h>
#include "InstructionRecorder.hpp"
#include "SingleInstruction.hpp"

using namespace ::testing;
using namespace InsPr;

class InstructionRecorderTestSuite : public Test
{
public:
    InstructionRecorder sut;
};

TEST_F(InstructionRecorderTestSuite, recordSingleBlock)
{
    sut << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut << boost::make_shared<SingleInstruction>(std::string("instruction2"));
    std::string expectedBlock("{\ninstruction1;\ninstruction2;\n}\n");

    ASSERT_TRUE(sut.getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F(InstructionRecorderTestSuite, recordBlockInBlock)
{
    sut << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut.startBlock();
    sut << boost::make_shared<SingleInstruction>(std::string("instruction2"));
    sut.finishBlock();

    std::string expectedBlock("{\ninstruction1;\n{\ninstruction2;\n}\n;\n}\n");
    ASSERT_TRUE(sut.getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F(InstructionRecorderTestSuite, blockAfterBlock)
{
    sut << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut.startBlock();
    sut << boost::make_shared<SingleInstruction>(std::string("instruction2"));
    sut.finishBlock();

    sut.startBlock();
    sut << boost::make_shared<SingleInstruction>(std::string("instruction3"));
    sut.finishBlock();

    std::string expectedBlock("{\ninstruction1;\n{\ninstruction2;\n}\n;\n{\ninstruction3;\n}\n;\n}\n");
    ASSERT_TRUE(sut.getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

