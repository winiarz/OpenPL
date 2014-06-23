#include<gtest/gtest.h>
#include "Kernel.hpp"
#include "Int.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"
#include "InstructionRecorderMock.hpp"

using namespace ::testing;
using namespace InsPr;

class KernelTestSuite : public Test
{
public:
    KernelTestSuite() 
    {}
};

TEST_F(KernelTestSuite, no_test)
{
    std::vector<std::shared_ptr<IGlobalArrayVariable>> args;
    args.push_back( std::make_shared<GlobalArrayVariable<Int>>( std::string("arg1") ) );
    args.push_back( std::make_shared<GlobalArrayVariable<Int>>( std::string("arg2") ) );

    auto  block = std::make_shared<InstructionBlock>();
    block->addInstruction( std::make_shared<SingleInstruction>(std::string("a = b + c")) );
    block->addInstruction( std::make_shared<SingleInstruction>(std::string("b = a + c")) );

    Kernel sut( std::string("exampleKernel"),
                args,
                block );

    ASSERT_EQ(1, sut.getAlternativesCount() );
    std::string expectedCode("__kernel void exampleKernel(__global int* arg1, __global int* arg2)\n{\na = b + c;\nb = a + c;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

