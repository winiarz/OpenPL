#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "TestWhileLoopSim.hpp"
#include <math.h>

class ForLoopTS : public ::testing::Test {
public:
  WhileLoopSim sim;
};

TEST_F( ForLoopTS, if_test )
{
  int loc_numbers[3] = {32,3,3};
  sim.numbers.copyIn(loc_numbers,0,3);
  sim.while_test(sim.numbers);
  int results[3];
  sim.numbers.copyOut(results,0,3);
  ASSERT_EQ( results[0], 2);
}

 