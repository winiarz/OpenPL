#include <gtest/gtest.h>
#include "IfInstruction.hpp"

using namespace ::testing;
using namespace InsPr;

class IfInstructionTestSuite : public Test
{
};

TEST_F(IfInstructionTestSuite, createIfWithoutElse)
{
    IfInstruction sut(boost::make_shared<SingleInstruction>(std::string("a != b")));
    sut.addInstruction(boost::make_shared<SingleInstruction>(std::string("cout << a << ' ' << b")));

    std::string expectedCode("if( a != b )\n{\ncout << a << ' ' << b;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

TEST_F(IfInstructionTestSuite, createIfWithElse)
{
    IfInstruction sut(boost::make_shared<SingleInstruction>(std::string("a < b")));
    sut.addInstruction(boost::make_shared<SingleInstruction>(std::string("cout << a << '<' << b")));

    sut.startElse();

    sut.addInstruction(boost::make_shared<SingleInstruction>(std::string("cout << a << '>' << b")));
    std::string expectedCode("if( a < b )\n{\ncout << a << '<' << b;\n}\nelse\n{\ncout << a << '>' << b;\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

