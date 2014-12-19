#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "mysim.hpp"
#include <math.h>

class ForLoopTS : public ::testing::Test {
public:
  IfCommandTestSim sim;
};

TEST_F( ForLoopTS, if_test )
{
  int loc_numbers[3] = {2,1,3};
  sim.numbers.copyIn(loc_numbers,0,3);
  sim.if_test(sim.numbers);
  int results[3];
  sim.numbers.copyOut(results,0,3);
  ASSERT_EQ( results[2], 123);
}

TEST_F( ForLoopTS, if_else_test )
{
  int loc_numbers[3] = {1,2,3};
  sim.numbers.copyIn(loc_numbers,0,3);
  sim.if_else_test(sim.numbers);
  int results[3];
  sim.numbers.copyOut(results,0,3);
  ASSERT_EQ( results[2], 321);
}


/*int main()
{
  
}*/
 
