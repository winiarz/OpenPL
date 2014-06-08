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
    KernelTestSuite() :
        recorderMock( boost::make_shared<InstructionRecorderMock>())
    {}

    boost::shared_ptr<InstructionRecorderMock> recorderMock;
};

TEST_F(KernelTestSuite, no_test)
{
    std::vector<boost::shared_ptr<IGlobalArrayVariable>> args;
    args.push_back( boost::make_shared<GlobalArrayVariable<Int>>( recorderMock, std::string("arg1") ) );
    args.push_back( boost::make_shared<GlobalArrayVariable<Int>>( recorderMock, std::string("arg2") ) );

    auto  block = boost::make_shared<InstructionBlock>();
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("a = b + c")) );
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("b = a + c")) );

    Kernel sut( std::string("exampleKernel"),
                args,
                block );

    ASSERT_EQ(1, sut.getAlternativesCount() );
    std::string expectedCode("__kenel void exampleKernel(__global int* arg1, __global int* arg2)\n{\na = b + c;\nb = a + c;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

