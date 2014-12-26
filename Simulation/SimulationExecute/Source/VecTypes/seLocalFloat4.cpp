#include "seLocalFloat4.hpp"

using namespace OPL::SimExec;

float& LocalFloat4::operator[](int n)
{
  return value[n];
}
