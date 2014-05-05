
#include "Simulation.hpp"
using namespace OPL;

const int IntegerConstant = 7;
const float FloatConstant = 3.14;

class MySim : public Simulation {
public:
  MEMORY( IntArray, numbers, 5);
  MEMORY( FloatArray, floats, 3);
  KERNEL_DEF1( constants, IntArray );
  KERNEL_DEF1( float_constans, FloatArray );
};
