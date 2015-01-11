#include "ClMemoryMaterialPointSOAWithSize.hpp"
#include "seLocalMaterialPoint.hpp"
#include <gtest/gtest.h>

namespace OPL
{

using namespace testing;

class ClMemoryMaterialPointSOAWithSizeTestSuite : public Test
{
public:
    ClMemoryMaterialPointSOAWithSizeTestSuite() :
        sut(100u)
    {}
protected:
    ClMemoryMaterialPointSOAWithSize sut;

};

TEST_F(ClMemoryMaterialPointSOAWithSizeTestSuite, whatYouCopyIn_isWhatYouCopyOut)
{
    SimExec::LocalMaterialPoint points[5];
    points[0].position[0] = 3.14f;
    points[1].position[2] = 2.73f;
    points[1].speed[1] = 1.55f;
    points[2].force[2] = 0.001f;
    points[0].mass = 1.234f;
    sut.copyIn(points, 0, 5);

    SimExec::LocalMaterialPoint copiedPoints[3];
    sut.copyOut(copiedPoints, 0, 3);
    ASSERT_EQ(3.14f, copiedPoints[0].position[0]);
    ASSERT_EQ(2.73f, copiedPoints[1].position[2]);
    ASSERT_EQ(1.55f, copiedPoints[1].speed[1]);
    ASSERT_EQ(0.001f, copiedPoints[2].force[2]);
    ASSERT_EQ(1.234f, copiedPoints[0].mass);
}

}

