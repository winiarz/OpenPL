#pragma once
#include "Simulation.hpp"
using namespace OPL;

const float scalar = 0.5;

class MySim : public Simulation {
public:
  MEMORY( MatrixFloat4x4Array, matrices, 3 );
  MEMORY( MatrixFloat3x3Array, matrices2, 3 );
  MEMORY( FloatArray, result, 1);
  SIMSTEP_DEF1( add, MatrixFloat4x4Array );
  SIMSTEP_DEF1( multiply, MatrixFloat4x4Array );
  SIMSTEP_DEF1( multiply_by_scalar, MatrixFloat4x4Array );
  SIMSTEP_DEF2( determinant, MatrixFloat4x4Array, FloatArray );
  
  
  SIMSTEP_DEF1( add3x3, MatrixFloat3x3Array);
  SIMSTEP_DEF1( mult3x3, MatrixFloat3x3Array);
  SIMSTEP_DEF2( determinant3x3, MatrixFloat3x3Array, FloatArray );
  SIMSTEP_DEF1( invert_3x3, MatrixFloat3x3Array);
};
