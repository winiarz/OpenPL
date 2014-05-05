
#include "mysim.hpp"

KERNEL_IMP1( MySim, while_test, IntArray, numbers)
{
  WHILE( numbers[0] > numbers[1], numbers[0] = numbers[0] / 2.0 )
}
