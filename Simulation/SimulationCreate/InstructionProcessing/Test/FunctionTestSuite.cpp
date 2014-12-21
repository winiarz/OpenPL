#include<gtest/gtest.h>
#include "Function.hpp"
#include "Int.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"
#include "InstructionRecorderMock.hpp"

namespace OPL
{
namespace InsPr
{

using namespace ::testing;

class FunctionTestSuite : public Test
{
public:
    FunctionTestSuite()
    {}
};

TEST_F(FunctionTestSuite, no_test)
{
    std::vector<shared_ptr<IVariable>> args;
    args.push_back( make_shared<Int>( std::string("number")) );
    args.push_back( make_shared<Int>( std::string("number")) );

    auto  block = make_shared<InstructionBlock>();
    block->addInstruction( make_shared<SingleInstruction>(std::string("a = b + c")) );
    block->addInstruction( make_shared<SingleInstruction>(std::string("b = a + c")) );
    

    Function sut(std::string("exampleFunction"),
                 args,
                 block );

    ASSERT_EQ(1, sut.getAlternativesCount());

    std::string expectedCode("void exampleFunction(int number, int number)\n{\na = b + c;\nb = a + c;\n}\n");
    ASSERT_TRUE( sut.getAlternative(0).compare(expectedCode) == 0);
}

}
}

