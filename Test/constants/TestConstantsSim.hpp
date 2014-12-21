
#include "Simulation.hpp"
using namespace OPL;

const int IntegerConstant = 7;
const float FloatConstant = 3.14;

class ConstantsSim : public Simulation {
public:
  MEMORY( IntArray, numbers, 5);
  MEMORY( FloatArray, floats, 3);
  SIMSTEP_DEF1( constants, IntArray );
  SIMSTEP_DEF1( float_constans, FloatArray );
};
