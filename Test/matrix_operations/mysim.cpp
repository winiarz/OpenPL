#include "mysim.hpp"

KERNEL_IMP1( MySim, add, Matrix4x4Array, matrices)
{
  matrices[0] = matrices[1] + matrices[2];
}

KERNEL_IMP1( MySim, multiply, Matrix4x4Array, matrices)
{
  matrices[0] = matrices[1] * matrices[2];
}

KERNEL_IMP1( MySim, multiply_by_scalar, Matrix4x4Array, matrices)
{
  matrices[0] = scalar * matrices[1];
}

KERNEL_IMP2( MySim, determinant, Matrix4x4Array, matrices, FloatArray, result)
{
  result[0] = det(matrices[0]);
}


KERNEL_IMP1( MySim, add3x3, Matrix3x3Array, matrices)
{
  matrices[0] = matrices[1] + matrices[2];
}

KERNEL_IMP1( MySim, mult3x3, Matrix3x3Array, matrices)
{
  matrices[0] = matrices[1] * matrices[2];
}

KERNEL_IMP2( MySim, determinant3x3, Matrix3x3Array, matrices, FloatArray, result)
{
  result[0] = det(matrices[0]);
}

KERNEL_IMP1( MySim, invert_3x3, Matrix3x3Array, matrices)
{
  matrices[1] = invert(matrices[0]);
  matrices[2] = matrices[0] * matrices[1];
}
