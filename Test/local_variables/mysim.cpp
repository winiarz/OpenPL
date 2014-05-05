
#include "mysim.hpp"

KERNEL_IMP0( MySim, empty)
{
  Int local_variable1;
  Int local_variable2;
  local_variable1 = 5;
  local_variable2 = local_variable2 + 2;
  Int4 loc_vector;
  loc_vector = local_variable1 * loc_vector;
}
