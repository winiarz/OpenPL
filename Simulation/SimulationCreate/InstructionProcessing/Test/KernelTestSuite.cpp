#include "Kernel.hpp"
#include "Type.hpp"
#include "Variable.hpp"
#include "InstructionBlock.hpp"
#include "SingleInstruction.hpp"
#include<gtest/gtest.h>

using namespace ::testing;
using namespace InsPr;

class KernelTestSuite : public Test
{

};

class Float : public IType
{
public:
    virtual std::string getTypeName()
    {
        return std::string("float");
    }
};

TEST_F(KernelTestSuite, no_test)
{
    std::vector<boost::shared_ptr<IGlobalArrayVariable>> args;
    args.push_back( boost::make_shared<GlobalArrayVariable<Float>>( std::string("arg1") ) );
    args.push_back( boost::make_shared<GlobalArrayVariable<Float>>( std::string("arg2") ) );

    auto  block = boost::make_shared<InstructionBlock>();
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("a = b + c;")) );
    block->addInstruction( boost::make_shared<SingleInstruction>(std::string("b = a + c;")) );

    Kernel sut( std::string("exampleKernel"),
                args,
                block );

    ASSERT_EQ(1, sut.getAlternativesCount() );
    std::cout << sut.getAlternative(0);
}

