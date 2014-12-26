#include "seLocalUint4.hpp"

using namespace OPL::SimExec;

uint& LocalUint4::operator[](int n)
{
  return value[n];
}
