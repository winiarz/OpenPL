#include "seLocalUint3.hpp"

using namespace OPL::SimExec;

uint& LocalUint3::operator[](int n)
{
  return value[n];
}
