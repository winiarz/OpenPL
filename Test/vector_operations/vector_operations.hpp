#include "Simulation.hpp"
using namespace OPL;

class MySim : public Simulation {
public:
  KERNEL_DEF1( vec_add, Int3Array );
  KERNEL_DEF1( vec_sub, Int3Array );
  KERNEL_DEF2( vec_mult, Float3Array, FloatArray);
  KERNEL_DEF2( vec_mult2, Float3Array, FloatArray);
  KERNEL_DEF2( vec_div, Float3Array, FloatArray);
  KERNEL_DEF2( vec_dot, Float3Array, FloatArray);
  KERNEL_DEF1( vec_cross, Float3Array);
  
  MEMORY( Int3Array, vectors, 10);
  MEMORY( FloatArray, scalars, 10);
  MEMORY( Float3Array, vectors2, 10);
};
