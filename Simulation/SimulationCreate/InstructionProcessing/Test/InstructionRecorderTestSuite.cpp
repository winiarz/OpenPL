#include <gtest/gtest.h>
#include "InstructionRecorder.hpp"
#include "SingleInstruction.hpp"
#include "Variable.hpp"
#include "Int.hpp"
#include "VectorVariable.hpp"
#include "IInstructionBlock.hpp"

namespace OPL
{
namespace InsPr
{

using namespace ::testing;

class InstructionRecorderTestSuite : public Test
{
public:
    InstructionRecorderTestSuite() :
        sut(make_shared<InstructionRecorder>())
    {}

    shared_ptr<IInstructionRecorder> sut;
};

TEST_F(InstructionRecorderTestSuite, recordSingleBlock)
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));
    std::string expectedBlock("{\ninstruction1;\ninstruction2;\n}\n");

    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F(InstructionRecorderTestSuite, recordBlockInBlock)
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startBlock();
    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));
    sut->finishBlock();

    std::string expectedBlock("{\ninstruction1;\n{\ninstruction2;\n}\n;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F(InstructionRecorderTestSuite, blockAfterBlock)
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startBlock();
    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));
    sut->finishBlock();

    sut->startBlock();
    (*sut) << make_shared<SingleInstruction>(std::string("instruction3"));
    sut->finishBlock();

    std::string expectedBlock("{\ninstruction1;\n{\ninstruction2;\n}\n;\n{\ninstruction3;\n}\n;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordForLoop )
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startForLoop(make_shared<SingleInstruction>(std::string("int i=0")),
                     make_shared<SingleInstruction>(std::string("i < 12")),
                     make_shared<SingleInstruction>(std::string("i++")) );

    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));

    sut->finishBlock();

    (*sut) << make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nfor(int i=0; i < 12; i++)\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordWhileLoop )
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startWhileLoop(make_shared<SingleInstruction>(std::string("a < b")) );

    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));

    sut->finishBlock();

    (*sut) << make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nwhile( a < b )\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordIfWithoutElse)
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startIf(make_shared<SingleInstruction>(std::string("a < b")) );

    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));

    sut->finishBlock();

    (*sut) << make_shared<SingleInstruction>(std::string("instruction3"));

    std::string expectedBlock("{\ninstruction1;\nif( a < b )\n{\ninstruction2;\n}\n;\ninstruction3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordIfWithElse)
{
    (*sut) << make_shared<SingleInstruction>(std::string("instruction1"));
    sut->startIf(make_shared<SingleInstruction>(std::string("a < b")) );

    (*sut) << make_shared<SingleInstruction>(std::string("instruction2"));
    sut->finishBlock();

    sut->startElse();
    (*sut) << make_shared<SingleInstruction>(std::string("instruction3"));
    sut->finishBlock();

    std::string expectedBlock("{\ninstruction1;\nif( a < b )\n{\ninstruction2;\n}\nelse\n{\ninstruction3;\n}\n;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordAssignment)
{
    sut = IVariable::recorder;
    Int number1( std::string("number1"));
    Int number2( std::string("number2")); 

    number1 = number2;

    std::string expectedBlock("{\nnumber1 = number2;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordAddition)
{
    sut = IVariable::recorder;
    Int number1( std::string("number1"));
    Int number2( std::string("number2")); 
    Int number3( std::string("number3"));

    number1 = number2 + number3;

    std::string expectedBlock("{\nnumber1 = number2 + number3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordSubstraction)
{
    sut = IVariable::recorder;
    Int number1( std::string("number1"));
    Int number2( std::string("number2")); 
    Int number3( std::string("number3"));

    number1 = number2 - number3;

    std::string expectedBlock("{\nnumber1 = number2 - number3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordMultiplication)
{
    sut = IVariable::recorder;
    Int number1( std::string("number1"));
    Int number2( std::string("number2")); 
    Int number3( std::string("number3"));

    number1 = number2 * number3;

    std::string expectedBlock("{\nnumber1 = number2 * number3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordDivision)
{
    sut = IVariable::recorder;
    Int number1( std::string("number1"));
    Int number2( std::string("number2")); 
    Int number3( std::string("number3"));

    number1 = number2 / number3;

    std::string expectedBlock("{\nnumber1 = number2 / number3;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordGetFromArray)
{
    sut = IVariable::recorder;
    Int number( std::string("number"));
    GlobalArrayVariable<Int> intArray( std::string("array"));
    Int index( std::string("index")); 

    number = intArray[index];

    std::string expectedBlock("{\nnumber = array[index];\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

TEST_F( InstructionRecorderTestSuite, recordStoreInArray)
{
    sut = IVariable::recorder;
    Int number( std::string("number"));
    GlobalArrayVariable<Int> intArray( std::string("array"));
    Int index( std::string("index")); 

    intArray[index] = number;

    std::string expectedBlock("{\narray[index] = number;\n}\n");
    ASSERT_TRUE(sut->getBlock()->getAlternative(0).compare(expectedBlock) == 0 );
}

}
}

