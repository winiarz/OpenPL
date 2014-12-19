
#include "mysim.hpp"

SIMSTEP_IMP1( IfCommandTestSim, if_test, IntArray, numbers)
{
    IF( numbers[0] > numbers[1] )
        numbers[2] = 123;
}

SIMSTEP_IMP1( IfCommandTestSim, if_else_test, IntArray, numbers)
{
    IF( numbers[0] > numbers[1] )
        numbers[2] = 123;
    ELSE
        numbers[2] = 321;
}
