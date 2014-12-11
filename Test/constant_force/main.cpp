#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "ConstantForceSim.hpp"

class ConstantForceTS : public ::testing::Test {
protected:
  ConstantForceSim sim;
};

TEST_F(ConstantForceTS, empty_test)
{
    sim.run();

    ASSERT_FLOAT_EQ(-3.0f, sim.localPoints[0].position[1]);
    ASSERT_FLOAT_EQ(-5.0f / 3.0f, sim.localPoints[1554].position[1]);
}

