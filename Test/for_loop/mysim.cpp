
#include "mysim.hpp"

SIMSTEP_IMP1( ForLoopSim, power, IntArray, numbers)
{
  InsPr::Int a = numbers[1];
  InsPr::Int n = numbers[2];
  InsPr::Int result;
  result = 1;
  InsPr::Int i;
  FOR( i = 0, i < n, i = i + 1 )
    result = result * a;
  numbers[0] = result;
}
