
#include "mysim.hpp"

KERNEL_IMP1( MySim, constants, IntArray, numbers)
{
  numbers[0] = IntegerConstant;
}

KERNEL_IMP1( MySim, float_constans, FloatArray, floats)
{ 
  floats[0] = FloatConstant;
}
