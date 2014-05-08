#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "mysim.hpp"
#include <math.h>

class ForLoopTS : public ::testing::Test {
public:
  MySim sim;
};

TEST_F( ForLoopTS, calculate_power )
{
  int loc_numbers[3] = {1,2,3};
  sim.numbers.copyIn(loc_numbers,0,3);
  sim.power(sim.numbers);
  int results[3];
  sim.numbers.copyOut(results,0,3);
  ASSERT_EQ( results[0], pow(loc_numbers[1],loc_numbers[2]));
}


/*int main()
{
  
}*/
 