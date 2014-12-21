#include <gtest/gtest.h>
#include "WhileLoop.hpp"

namespace OPL
{
namespace InsPr
{

using namespace ::testing;

class WhileLoopTestSuite : public Test
{

};

TEST_F(WhileLoopTestSuite, testWhileLoop)
{
    WhileLoop sut(make_shared<SingleInstruction>(std::string("a != b")));
    sut.addInstruction(make_shared<SingleInstruction>(std::string("cout << a << ' ' << b")));

    std::string expectedCode("while( a != b )\n{\ncout << a << ' ' << b;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

}
}

