#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "copy_integers.hpp"

class CopyIntegersTS : public ::testing::Test {
protected:
  CopyIntegersSim sim;
};

TEST_F(CopyIntegersTS, copy_integer)
{
  int loc_liczby[2] = { 1, 2 };
  sim.liczby.copyIn( loc_liczby, 0, 2);
  sim.copy(sim.liczby);
  sim.liczby.copyOut( loc_liczby, 0, 2);
  ASSERT_EQ(loc_liczby[0], loc_liczby[1]);
}
