#include "mysim.hpp"

SIMSTEP_IMP1( MySim, add, MatrixFloat4x4Array, matrices)
{
  matrices[0] = matrices[1] + matrices[2];
}

SIMSTEP_IMP1( MySim, multiply, MatrixFloat4x4Array, matrices)
{
  matrices[0] = matrices[1] * matrices[2];
}

SIMSTEP_IMP1( MySim, multiply_by_scalar, MatrixFloat4x4Array, matrices)
{
  matrices[0] = scalar * matrices[1];
}

SIMSTEP_IMP2( MySim, determinant, MatrixFloat4x4Array, matrices, FloatArray, result)
{
  result[0] = matrices[0].det();
}


SIMSTEP_IMP1( MySim, add3x3, MatrixFloat3x3Array, matrices)
{
  matrices[0] = matrices[1] + matrices[2];
}

SIMSTEP_IMP1( MySim, mult3x3, MatrixFloat3x3Array, matrices)
{
  matrices[0] = matrices[1] * matrices[2];
}

SIMSTEP_IMP2( MySim, determinant3x3, MatrixFloat3x3Array, matrices, FloatArray, result)
{
  result[0] = matrices[0].det();
}

SIMSTEP_IMP1( MySim, invert_3x3, MatrixFloat3x3Array, matrices)
{
  matrices[1] = invert(matrices[0]);
  matrices[2] = matrices[0] * matrices[1];
}

