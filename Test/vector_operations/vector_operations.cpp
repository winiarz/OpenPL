#include "vector_operations.hpp"

KERNEL_IMP1( MySim, vec_add, Int3Array, vectors)
{
  vectors[0] = vectors[1] + vectors[2];
}

KERNEL_IMP1( MySim, vec_sub, Int3Array, vectors)
{
  vectors[0] = vectors[1] - vectors[2];
}

KERNEL_IMP2( MySim, vec_dot, Float3Array, vectors, FloatArray, result)
{
  result[0] = vectors[0] * vectors[1];
}

KERNEL_IMP1( MySim, vec_cross, Float3Array, vectors)
{
  vectors[0] = vectors[1] ^ vectors[2];
}

KERNEL_IMP2( MySim, vec_mult, Float3Array, vectors, FloatArray, scalar)
{
  vectors[0] = vectors[1] * scalar[0];
}

KERNEL_IMP2( MySim, vec_mult2, Float3Array, vectors, FloatArray, scalar)
{
  vectors[0] = scalar[0] * vectors[1];
}

KERNEL_IMP2( MySim, vec_div, Float3Array, vectors, FloatArray, scalar)
{
  vectors[0] = vectors[1] / scalar[0];
}
