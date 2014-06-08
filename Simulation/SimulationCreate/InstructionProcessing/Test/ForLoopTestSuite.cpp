#include <gtest/gtest.h>
#include "ForLoop.hpp"
#include "SingleInstruction.hpp"

using namespace ::testing;
using namespace InsPr;

class ForLoopTestSuite : public Test
{

};

TEST_F( ForLoopTestSuite, creteFolLoop)
{
    ForLoop sut( boost::make_shared<SingleInstruction>(std::string("int i=0")),
                 boost::make_shared<SingleInstruction>(std::string("i < 10")),
                 boost::make_shared<SingleInstruction>(std::string("i++")) );

    sut.addInstruction(boost::make_shared<SingleInstruction>(std::string("cout << i << ' '")));

    std::string expectedCode("for(int i=0; i < 10; i++)\n{\ncout << i << ' ';\n}\n");
    ASSERT_TRUE(sut.getAlternative(0).compare(expectedCode) == 0 );
}

