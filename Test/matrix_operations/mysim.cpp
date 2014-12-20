#include "mysim.hpp"

SIMSTEP_IMP1( MatrixOperationSim, add, MatrixFloat4x4Array, matrices)
{
  matrices[0] = matrices[1] + matrices[2];
}

SIMSTEP_IMP1( MatrixOperationSim, multiply, MatrixFloat4x4Array, matrices)
{
  matrices[0] = matrices[1] * matrices[2];
}

SIMSTEP_IMP1( MatrixOperationSim, multiply_by_scalar, MatrixFloat4x4Array, matrices)
{
  matrices[0] = scalar * matrices[1];
}

SIMSTEP_IMP2( MatrixOperationSim, determinant, MatrixFloat4x4Array, matrices, FloatArray, result)
{
  result[0] = matrices[0].det();
}


SIMSTEP_IMP1( MatrixOperationSim, add3x3, MatrixFloat3x3Array, matrices)
{
  matrices[0] = matrices[1] + matrices[2];
}

SIMSTEP_IMP1( MatrixOperationSim, mult3x3, MatrixFloat3x3Array, matrices)
{
  matrices[0] = matrices[1] * matrices[2];
}

SIMSTEP_IMP2( MatrixOperationSim, determinant3x3, MatrixFloat3x3Array, matrices, FloatArray, result)
{
  result[0] = matrices[0].det();
}

SIMSTEP_IMP1( MatrixOperationSim, invert_3x3, MatrixFloat3x3Array, matrices)
{
  matrices[1] = matrices[0].invert();
  matrices[2] = matrices[0] * matrices[1];
}

