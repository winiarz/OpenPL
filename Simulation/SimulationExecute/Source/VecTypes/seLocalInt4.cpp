#include "seLocalInt4.hpp"

using namespace OPL::SimExec;

int& LocalInt4::operator[](int n)
{
  return value[n];
}
