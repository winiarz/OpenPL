#include "Simulation.hpp"
using namespace OPL;

class VectorOperationsSim : public Simulation {
public:
  SIMSTEP_DEF1( vec_add, Int3Array );
  SIMSTEP_DEF1( vec_sub, Int3Array );
  SIMSTEP_DEF2( vec_mult, Float3Array, FloatArray);
  SIMSTEP_DEF2( vec_mult2, Float3Array, FloatArray);
  SIMSTEP_DEF2( vec_div, Float3Array, FloatArray);
  SIMSTEP_DEF2( vec_dot, Float3Array, FloatArray);
  SIMSTEP_DEF1( vec_cross, Float3Array);
  
  MEMORY( Int3Array, vectors, 10);
  MEMORY( FloatArray, scalars, 10);
  MEMORY( Float3Array, vectors2, 10);
};
