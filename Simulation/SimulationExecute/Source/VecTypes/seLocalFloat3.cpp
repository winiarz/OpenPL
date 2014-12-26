#include "seLocalFloat3.hpp"

using namespace OPL::SimExec;

float& LocalFloat3::operator[](int n)
{
  return value[n];
}
