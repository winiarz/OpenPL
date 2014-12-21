#include<boost/scoped_ptr.hpp>
#include<gtest/gtest.h>
#include "IntGlobalArray.hpp"
#include "InstructionRecorder.hpp"

namespace OPL
{
namespace InsPr
{

using namespace ::testing;

class GlobalArrayTestSuite : public Test
{

};

TEST_F( GlobalArrayTestSuite, copyElements )
{
    auto recorder = IVariable::recorder;
    IntArrayGlobal intArray ( "intArray" );
    Int index1( "index1" );
    Int index2( "index2" );

    intArray[index1] = intArray[index2];

    std::string expectedInstruction("{\nintArray[index1] = intArray[index2];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, copyElementsWithConstant )
{
    auto recorder = IVariable::recorder;
    IntArrayGlobal intArray ( "intArray" );
    Int index2( "index2" );

    intArray[0] = intArray[index2];

    std::string expectedInstruction("{\nintArray[0] = intArray[index2];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, writeConstantIntoArray )
{
    auto recorder = IVariable::recorder;
    IntArrayGlobal intArray ( "intArray" );

    intArray[0] = 5;

    std::string expectedInstruction("{\nintArray[0] = 5;\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, readFromArray )
{
    auto recorder = IVariable::recorder;
    IntArrayGlobal intArray ( "intArray" );

    Int number( "number" );
    number = intArray[0];

    std::string expectedInstruction("{\nnumber = intArray[0];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, arrayAsIndexOfArray )
{
    auto recorder = IVariable::recorder;
    IntArrayGlobal intArray ( "intArray" );

    Int number( "number" );
    number = intArray[intArray[0]];

    std::string expectedInstruction("{\nnumber = intArray[intArray[0]];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

}
}

