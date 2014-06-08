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

TEST_F( InstructionRecorderTestSuite, recordForLoop )
{
    sut << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut.startForLoop(boost::make_shared<SingleInstruction>(std::string("int i=0")),
                     boost::make_shared<SingleInstruction>(std::string("i < 12")),
                     boost::make_shared<SingleInstruction>(std::string("i++")) );

    sut << boost::make_shared<SingleInstruction>(std::string("instruction2"));

    sut.finishBlock();

    sut << boost::make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nfor(int i=0; i < 12; i++)\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut.getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordWhileLoop )
{
    sut << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut.startWhileLoop(boost::make_shared<SingleInstruction>(std::string("a < b")) );

    sut << boost::make_shared<SingleInstruction>(std::string("instruction2"));

    sut.finishBlock();

    sut << boost::make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nwhile( a < b )\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut.getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

