
#include "TestConstantsSim.hpp"

SIMSTEP_IMP1( ConstantsSim, constants, IntArray, numbers)
{
  numbers[0] = IntegerConstant;
}

SIMSTEP_IMP1( ConstantsSim, float_constans, FloatArray, floats)
{ 
  floats[0] = FloatConstant;
}
