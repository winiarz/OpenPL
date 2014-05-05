
#include "mysim.hpp"

KERNEL_IMP1( MySim, power, IntArray, numbers)
{
  Int a = numbers[1];
  Int n = numbers[2];
  Int result = 1;
  Int i;
  FOR( i,0,n, result = result * a)
  numbers[0] = result;
}
