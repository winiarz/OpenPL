#include <gtest/gtest.h>
#include "ForLoop.hpp"
#include "SingleInstruction.hpp"

namespace OPL
{
namespace InsPr
{

using namespace ::testing;

class ForLoopTestSuite : public Test
{
};

TEST_F( ForLoopTestSuite, creteFolLoop)
{
    ForLoop sut( make_shared<SingleInstruction>(std::string("int i=0")),
                 make_shared<SingleInstruction>(std::string("i < 10")),
                 make_shared<SingleInstruction>(std::string("i++")) );

    sut.addInstruction(make_shared<SingleInstruction>(std::string("cout << i << ' '")));

    std::string expectedCode("for(int i=0; i < 10; i++)\n{\ncout << i << ' ';\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

}
}

