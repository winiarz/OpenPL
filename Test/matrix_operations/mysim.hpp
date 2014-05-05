
#include "Simulation.hpp"
using namespace OPL;

const float scalar = 0.5;

class MySim : public Simulation {
public:
  MEMORY( Matrix4x4Array, matrices, 3 );
  MEMORY( Matrix3x3Array, matrices2, 3 );
  MEMORY( FloatArray, result, 1);
  KERNEL_DEF1( add, Matrix4x4Array );
  KERNEL_DEF1( multiply, Matrix4x4Array );
  KERNEL_DEF1( multiply_by_scalar, Matrix4x4Array );
  KERNEL_DEF2( determinant, Matrix4x4Array, FloatArray );
  
  KERNEL_DEF1( add3x3, Matrix3x3Array);
  KERNEL_DEF1( mult3x3, Matrix3x3Array);
  KERNEL_DEF2( determinant3x3, Matrix3x3Array, FloatArray );
  KERNEL_DEF1( invert_3x3, Matrix3x3Array);
};
