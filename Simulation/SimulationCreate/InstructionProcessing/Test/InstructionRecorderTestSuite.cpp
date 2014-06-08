#include <gtest/gtest.h>
#include "InstructionRecorder.hpp"
#include "SingleInstruction.hpp"
#include "Int.hpp"

using namespace ::testing;
using namespace InsPr;

class InstructionRecorderTestSuite : public Test
{
public:
    InstructionRecorderTestSuite() :
        sut(boost::make_shared<InstructionRecorder>())
    {}

    boost::shared_ptr<InstructionRecorder> sut;
};

TEST_F(InstructionRecorderTestSuite, recordSingleBlock)
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));
    std::string expectedBlock("{\ninstruction1;\ninstruction2;\n}\n");

    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F(InstructionRecorderTestSuite, recordBlockInBlock)
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startBlock();
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));
    sut->finishBlock();

    std::string expectedBlock("{\ninstruction1;\n{\ninstruction2;\n}\n;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F(InstructionRecorderTestSuite, blockAfterBlock)
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startBlock();
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));
    sut->finishBlock();

    sut->startBlock();
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction3"));
    sut->finishBlock();

    std::string expectedBlock("{\ninstruction1;\n{\ninstruction2;\n}\n;\n{\ninstruction3;\n}\n;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordForLoop )
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startForLoop(boost::make_shared<SingleInstruction>(std::string("int i=0")),
                     boost::make_shared<SingleInstruction>(std::string("i < 12")),
                     boost::make_shared<SingleInstruction>(std::string("i++")) );

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));

    sut->finishBlock();

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nfor(int i=0; i < 12; i++)\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordWhileLoop )
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startWhileLoop(boost::make_shared<SingleInstruction>(std::string("a < b")) );

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));

    sut->finishBlock();

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nwhile( a < b )\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordIfWithoutElse)
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startIf(boost::make_shared<SingleInstruction>(std::string("a < b")) );

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));

    sut->finishBlock();

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nif( a < b )\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordIfWithElse)
{
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startIf(boost::make_shared<SingleInstruction>(std::string("a < b")) );

    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction2"));

    sut->startElse();
    (*sut) << boost::make_shared<SingleInstruction>(std::string("instruction3"));
    sut->finishBlock();

    std::string expectedBlock("{\ninstruction1;\nif( a < b )\n{\ninstruction2;\n}\nelse\n{\ninstruction3;\n}\n;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordAssignment)
{
    Int number1(sut, std::string("number1"));
    Int number2(sut, std::string("number2")); 

    number1 = number2;

    std::string expectedBlock("{\nnumber1 = number2;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordAddition)
{
    Int number1(sut, std::string("number1"));
    Int number2(sut, std::string("number2")); 
    Int number3(sut, std::string("number3"));

    number1 = (number2 + number3);

    std::string expectedBlock("{\nnumber1 = number2 + number3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}
