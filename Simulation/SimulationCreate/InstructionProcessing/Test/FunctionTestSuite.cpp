#include "Function.hpp"
#include "Type.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"
#include<gtest/gtest.h>

using namespace ::testing;
using namespace InsPr;

class FunctionTestSuite : public Test
{

};

TEST_F(FunctionTestSuite, no_test)
{
    auto type = boost::make_shared<Type>(std::string("int"));

    std::vector<boost::shared_ptr<IVariable>> args;
    args.push_back( boost::make_shared<Variable>(type, std::string("number")) );
    args.push_back( boost::make_shared<Variable>(type, std::string("number")) );

    auto  block = boost::make_shared<InstructionBlock>();
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("a = b + c;")) );
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("b = a + c;")) );
    

    Function sut(std::string("exampleFunction"),
                 args,
                 block );

    ASSERT_EQ(1, sut.getAlternativesCount());
    std::cout << sut.getAlternative(0);

}

