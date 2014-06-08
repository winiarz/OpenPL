#include<gtest/gtest.h>
#include "Function.hpp"
#include "Int.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"
#include "InstructionRecorderMock.hpp"

using namespace ::testing;
using namespace InsPr;

class FunctionTestSuite : public Test
{
public:
    FunctionTestSuite() :
        recorderMock( boost::make_shared<InstructionRecorderMock>())
    {}

    boost::shared_ptr<InstructionRecorderMock> recorderMock;
};

TEST_F(FunctionTestSuite, no_test)
{
    std::vector<boost::shared_ptr<IVariable>> args;
    args.push_back( make_shared<Int>( recorderMock, std::string("number")) );
    args.push_back( make_shared<Int>( recorderMock, std::string("number")) );

    auto  block = boost::make_shared<InstructionBlock>();
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("a = b + c")) );
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("b = a + c")) );
    

    Function sut(std::string("exampleFunction"),
                 args,
                 block );

    ASSERT_EQ(1, sut.getAlternativesCount());

    std::string expectedCode("void exampleFunction(int number, int number)\n{\na = b + c;\nb = a + c;\n}\n");
    ASSERT_TRUE( sut.getAlternative(0).compare(expectedCode) == 0);
}

