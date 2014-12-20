
#include "mysim.hpp"

SIMSTEP_IMP0( LocalVariablesSim, empty)
{
  InsPr::Int local_variable1;
  InsPr::Int local_variable2;
  local_variable1 = 5;
  local_variable2 = local_variable2 + InsPr::Int(2);
  InsPr::Int4 loc_vector;
  loc_vector = local_variable1 * loc_vector;
}
