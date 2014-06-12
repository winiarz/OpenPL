#include<boost/scoped_ptr.hpp>
#include<gtest/gtest.h>
#include "IntGlobalArray.hpp"
#include "InstructionRecorder.hpp"

using namespace ::testing;
using namespace InsPr;

class GlobalArrayTestSuite : public Test
{

};

TEST_F( GlobalArrayTestSuite, copyElements )
{
    auto recorder = boost::make_shared<InstructionRecorder>();
    IntGlobalArray intArray ( recorder, "intArray" );
    Int index1( recorder, "index1" );
    Int index2( recorder, "index2" );

    intArray[index1] = intArray[index2];

    std::string expectedInstruction("{\nintArray[index1] = intArray[index2];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, copyElementsWithConstant )
{
    auto recorder = boost::make_shared<InstructionRecorder>();
    IntGlobalArray intArray ( recorder, "intArray" );
    Int index2( recorder, "index2" );

    intArray[0] = intArray[index2];

    std::string expectedInstruction("{\nintArray[0] = intArray[index2];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, writeConstantIntoArray )
{
    auto recorder = boost::make_shared<InstructionRecorder>();
    IntGlobalArray intArray ( recorder, "intArray" );

    intArray[0] = 5;

    std::string expectedInstruction("{\nintArray[0] = 5;\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, readFromArray )
{
    auto recorder = boost::make_shared<InstructionRecorder>();
    IntGlobalArray intArray ( recorder, "intArray" );

    Int number( recorder, "number" );
    number = intArray[0];

    std::string expectedInstruction("{\nnumber = intArray[0];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

TEST_F( GlobalArrayTestSuite, arrayAsIndexOfArray )
{
    auto recorder = boost::make_shared<InstructionRecorder>();
    IntGlobalArray intArray ( recorder, "intArray" );

    Int number( recorder, "number" );
    number = intArray[intArray[0]];

    std::string expectedInstruction("{\nnumber = intArray[intArray[0]];\n}\n");
    ASSERT_TRUE(recorder->getBlock()->getAlternative(0).compare(expectedInstruction) == 0 );
}

