#include "TestVectorOperationsSim.hpp"

SIMSTEP_IMP1( VectorOperationsSim, vec_add, Int3Array, vectors)
{
  vectors[0] = vectors[1] + vectors[2];
}

SIMSTEP_IMP1( VectorOperationsSim, vec_sub, Int3Array, vectors)
{
  vectors[0] = vectors[1] - vectors[2];
}

SIMSTEP_IMP2( VectorOperationsSim, vec_dot, Float3Array, vectors, FloatArray, result)
{
   result[0] = InsPr::Float3(vectors[0]) * InsPr::Float3(vectors[1]);
}

SIMSTEP_IMP1( VectorOperationsSim, vec_cross, Float3Array, vectors)
{
  vectors[0] = vectors[1] ^ vectors[2];
}

SIMSTEP_IMP2( VectorOperationsSim, vec_mult, Float3Array, vectors, FloatArray, scalar)
{
  vectors[0] = vectors[1] * scalar[0];
}

SIMSTEP_IMP2( VectorOperationsSim, vec_mult2, Float3Array, vectors, FloatArray, scalar)
{
  vectors[0] = scalar[0] * vectors[1];
}

SIMSTEP_IMP2( VectorOperationsSim, vec_div, Float3Array, vectors, FloatArray, scalar)
{
  vectors[0] = vectors[1] / scalar[0];
}
