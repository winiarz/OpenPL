
struct Matrix_float_3x3
{
    float4 A[4]; 
};

struct Matrix_float_3x3 addMatrix( struct Matrix_float_3x3 first, struct Matrix_float_3x3 second )
{
    struct Matrix_float_3x3 result;
    result.A[0] = first.A[0] + second.A[0];
    result.A[1] = first.A[1] + second.A[1];
    result.A[2] = first.A[2] + second.A[2];
    return result;
} 

struct Matrix_float_3x3 subMatrix( struct Matrix_float_3x3 first, struct Matrix_float_3x3 second )
{
    struct Matrix_float_3x3 result;
    result.A[0] = first.A[0] - second.A[0];
    result.A[1] = first.A[1] - second.A[1];
    result.A[2] = first.A[2] - second.A[2];
    return result;
} 

struct Matrix_float_3x3 multMatrix( struct Matrix_float_3x3 first, struct Matrix_float_3x3 second )
{
    struct Matrix_float_3x3 result;
    result.A[0] = first.A[0].s0 * second.A[0] + first.A[0].s1 * second.A[1] + first.A[0].s2 * second.A[2];
    result.A[1] = first.A[1].s0 * second.A[0] + first.A[1].s1 * second.A[1] + first.A[1].s2 * second.A[2];
    result.A[2] = first.A[2].s0 * second.A[0] + first.A[2].s1 * second.A[1] + first.A[2].s2 * second.A[2];
    return result;
}

struct Matrix_float_3x3 multMatrix3x3ByScalar( struct Matrix_float_3x3 matrix, float scalar )
{
    struct Matrix_float_3x3 result;
    result.A[0] = matrix.A[0] * scalar;
    result.A[1] = matrix.A[1] * scalar;
    result.A[2] = matrix.A[2] * scalar;
    return result;
}

struct Matrix_float_3x3 multScalarByMatrix3x4( float scalar, struct Matrix_float_3x3 matrix )
{
    struct Matrix_float_3x3 result;
    result.A[0] = matrix.A[0] * scalar;
    result.A[1] = matrix.A[1] * scalar;
    result.A[2] = matrix.A[2] * scalar;
    return result;
}

float matrix3x3_determinant(struct Matrix_float_3x3 matrix)
{
  float d0 = matrix.A[0].s0 * (matrix.A[1].s1 * matrix.A[2].s2 - matrix.A[1].s2 * matrix.A[2].s1);
  float d1 = matrix.A[0].s1 * (matrix.A[1].s0 * matrix.A[2].s2 - matrix.A[1].s2 * matrix.A[2].s0);
  float d2 = matrix.A[0].s2 * (matrix.A[1].s0 * matrix.A[2].s1 - matrix.A[1].s1 * matrix.A[2].s0);
  return d0 - d1 + d2;
}

struct Matrix_float_3x3 invertMatrix3x3(struct Matrix_float_3x3 matrix)
{
  struct Matrix_float_3x3 result;
  result.A[0].s0 = matrix.A[1].s1 * matrix.A[2].s2 - matrix.A[2].s1 * matrix.A[1].s2;
  result.A[0].s1 = matrix.A[0].s2 * matrix.A[2].s1 - matrix.A[0].s1 * matrix.A[2].s2;
  result.A[0].s2 = matrix.A[1].s0 * matrix.A[2].s1 - matrix.A[1].s1 * matrix.A[2].s0;
  
  result.A[1].s0 = matrix.A[1].s2 * matrix.A[2].s0 - matrix.A[1].s0 * matrix.A[2].s2;
  result.A[1].s1 = matrix.A[0].s0 * matrix.A[2].s2 - matrix.A[0].s2 * matrix.A[2].s0;
  result.A[1].s2 = matrix.A[1].s0 * matrix.A[0].s2 - matrix.A[0].s0 * matrix.A[1].s2;
  
  result.A[2].s0 = matrix.A[1].s0 * matrix.A[2].s1 - matrix.A[1].s1 * matrix.A[2].s0;
  result.A[2].s1 = matrix.A[0].s1 * matrix.A[2].s0 - matrix.A[0].s0 * matrix.A[2].s1;
  result.A[2].s2 = matrix.A[0].s0 * matrix.A[1].s1 - matrix.A[0].s1 * matrix.A[1].s0;

  float det = matrix3x3_determinant(matrix);
  result.A[0] /= det;
  result.A[1] /= det;
  result.A[2] /= det;
  return result;
}

