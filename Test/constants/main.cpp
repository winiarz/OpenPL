#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "mysim.hpp"

class ConstantsTS : public ::testing::Test {
protected:
  ConstantsSim sim;
};

TEST_F( ConstantsTS, integer_constant )
{
  sim.constants( sim.numbers );
  int loc_numbers[1];
  sim.numbers.copyOut( loc_numbers, 0, 1 );
  ASSERT_EQ( loc_numbers[0], IntegerConstant );
}

TEST_F( ConstantsTS, float_constant )
{
  sim.float_constans( sim.floats );
  float loc_floats[1];
  sim.floats.copyOut( loc_floats, 0, 1 );
  ASSERT_FLOAT_EQ( loc_floats[0], FloatConstant );
}
