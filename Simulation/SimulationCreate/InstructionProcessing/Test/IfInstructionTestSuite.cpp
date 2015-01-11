#include <gtest/gtest.h>
#include "IfInstruction.hpp"

namespace OPL
{
namespace InsPr
{

using namespace ::testing;

class IfInstructionTestSuite : public Test
{
};

TEST_F(IfInstructionTestSuite, createIfWithoutElse)
{
    IfInstruction sut(std::make_shared<SingleInstruction>(std::string("a != b")));
    sut.addInstruction(std::make_shared<SingleInstruction>(std::string("cout << a << ' ' << b")));

    std::string expectedCode("if( a != b )\n{\ncout << a << ' ' << b;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

TEST_F(IfInstructionTestSuite, createIfWithElse)
{
    IfInstruction sut(std::make_shared<SingleInstruction>(std::string("a < b")));
    sut.addInstruction(std::make_shared<SingleInstruction>(std::string("cout << a << '<' << b")));

    sut.startElse();

    sut.addInstruction(std::make_shared<SingleInstruction>(std::string("cout << a << '>' << b")));
    std::string expectedCode("if( a < b )\n{\ncout << a << '<' << b;\n}\nelse\n{\ncout << a << '>' << b;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

}
}

