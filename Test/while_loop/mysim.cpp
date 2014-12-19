
#include "mysim.hpp"

SIMSTEP_IMP1( WhileLoopSim, while_test, IntArray, numbers)
{
  WHILE( numbers[0] > numbers[1] )
    numbers[0] = numbers[0] / InsPr::Int(2);
}
