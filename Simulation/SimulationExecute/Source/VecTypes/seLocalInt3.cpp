#include "seLocalInt3.hpp"

using namespace OPL::SimExec;

int& LocalInt3::operator[](int n)
{
  return value[n];
}
