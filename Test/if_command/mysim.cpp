
#include "mysim.hpp"

KERNEL_IMP1( MySim, if_test, IntArray, numbers)
{
  IF( numbers[0] > numbers[1], numbers[2] = 123 )
}

KERNEL_IMP1( MySim, if_else_test, IntArray, numbers)
{
  IF_ELSE( numbers[0] > numbers[1], numbers[2] = 123, numbers[2] = 321 )
}