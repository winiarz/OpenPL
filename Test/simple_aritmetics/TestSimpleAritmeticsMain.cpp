#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "TestSimpleAritmeticsSim.hpp"

class CopyIntegersTS : public ::testing::Test {
protected:
  SimpleAritmeticsSim sim;
};

TEST_F(CopyIntegersTS, add_integer)
{
  int loc_liczby[3] = { 6, 2, 4 };
  sim.liczby.copyIn( loc_liczby, 0, 3);
  sim.add(sim.liczby);
  sim.liczby.copyOut( loc_liczby, 0, 3);
  ASSERT_EQ(loc_liczby[2], loc_liczby[1] + loc_liczby[0]);
}

TEST_F(CopyIntegersTS, substract_integer)
{
  int loc_liczby[3] = { 11, 52, 3 };
  sim.liczby.copyIn( loc_liczby, 0, 3);
  sim.sub(sim.liczby);
  sim.liczby.copyOut( loc_liczby, 0, 3);
  ASSERT_EQ(loc_liczby[2], loc_liczby[1] - loc_liczby[0]);
}

TEST_F(CopyIntegersTS, multiply_integer)
{
  int loc_liczby[3] = { 11, 77, 3 };
  sim.liczby.copyIn( loc_liczby, 0, 3);
  sim.mult(sim.liczby);
  sim.liczby.copyOut( loc_liczby, 0, 3);
  ASSERT_EQ(loc_liczby[2], loc_liczby[1] * loc_liczby[0]);
}

TEST_F(CopyIntegersTS, divide_integer)
{
  int loc_liczby[3] = { 11, 52, 3 };
  sim.liczby.copyIn( loc_liczby, 0, 3);
  sim.div(sim.liczby);
  sim.liczby.copyOut( loc_liczby, 0, 3);
  ASSERT_EQ(loc_liczby[2], loc_liczby[1] / loc_liczby[0]);
}

TEST_F(CopyIntegersTS, modulo_integer)
{
  int loc_liczby[3] = { 11, 52, 3 };
  sim.liczby.copyIn( loc_liczby, 0, 3);
  sim.mod(sim.liczby);
  sim.liczby.copyOut( loc_liczby, 0, 3);
  ASSERT_EQ(loc_liczby[2], loc_liczby[1] % loc_liczby[0]);
}
