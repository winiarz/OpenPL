
struct Matrix_float_4x4
{
    float4 A[4]; 
};

struct Matrix_float_4x4 addMatrix( struct Matrix_float_4x4 first, struct Matrix_float_4x4 second )
{
    struct Matrix_float_4x4 result;
    result.A[0] = first.A[0] + second.A[0];
    result.A[1] = first.A[1] + second.A[1];
    result.A[2] = first.A[2] + second.A[2];
    result.A[3] = first.A[3] + second.A[3];
    return result;
}

struct Matrix_float_4x4 subMatrix( struct Matrix_float_4x4 first, struct Matrix_float_4x4 second )
{
    struct Matrix_float_4x4 result;
    result.A[0] = first.A[0] - second.A[0];
    result.A[1] = first.A[1] - second.A[1];
    result.A[2] = first.A[2] - second.A[2];
    result.A[3] = first.A[3] - second.A[3];
    return result;
}

struct Matrix_float_4x4 multMatrix( struct Matrix_float_4x4 first, struct Matrix_float_4x4 second )
{
    struct Matrix_float_4x4 result;
    result.A[0] = first.A[0].s0 * second.A[0] + first.A[0].s1 * second.A[1] + first.A[0].s2 * second.A[2] + first.A[0].s3 * second.A[3];
    result.A[1] = first.A[1].s0 * second.A[0] + first.A[1].s1 * second.A[1] + first.A[1].s2 * second.A[2] + first.A[1].s3 * second.A[3];
    result.A[2] = first.A[2].s0 * second.A[0] + first.A[2].s1 * second.A[1] + first.A[2].s2 * second.A[2] + first.A[2].s3 * second.A[3];
    result.A[3] = first.A[3].s0 * second.A[0] + first.A[3].s1 * second.A[1] + first.A[3].s2 * second.A[2] + first.A[3].s3 * second.A[3];
    return result;
}

struct Matrix_float_4x4 multMatrix4x4ByScalar( struct Matrix_float_4x4 matrix, float scalar )
{
    struct Matrix_float_4x4 result;
    result.A[0] = matrix.A[0] * scalar;
    result.A[1] = matrix.A[1] * scalar;
    result.A[2] = matrix.A[2] * scalar;
    result.A[3] = matrix.A[3] * scalar;
    return result;
}

struct Matrix_float_4x4 multScalarByMatrix4x4( float scalar, struct Matrix_float_4x4 matrix )
{
    struct Matrix_float_4x4 result;
    result.A[0] = matrix.A[0] * scalar;
    result.A[1] = matrix.A[1] * scalar;
    result.A[2] = matrix.A[2] * scalar;
    result.A[3] = matrix.A[3] * scalar;
    return result;
}

float matrix4x4_determinant(struct Matrix_float_4x4 matrix)
{
  float d01 = matrix.A[0].s0 * matrix.A[1].s1 - matrix.A[0].s1 * matrix.A[1].s0;
  float d02 = matrix.A[0].s0 * matrix.A[1].s2 - matrix.A[0].s2 * matrix.A[1].s0;
  float d03 = matrix.A[0].s0 * matrix.A[1].s3 - matrix.A[0].s3 * matrix.A[1].s0;
  float d12 = matrix.A[0].s1 * matrix.A[1].s2 - matrix.A[0].s2 * matrix.A[1].s1;
  float d13 = matrix.A[0].s1 * matrix.A[1].s3 - matrix.A[0].s3 * matrix.A[1].s1;
  float d23 = matrix.A[0].s2 * matrix.A[1].s3 - matrix.A[0].s3 * matrix.A[1].s2;
  
  float d3 = ( d01 * matrix.A[2].s2 - d02 * matrix.A[2].s1 + d12 * matrix.A[2].s0 ) * matrix.A[3].s3;
  float d2 = ( d01 * matrix.A[2].s3 - d03 * matrix.A[2].s1 + d13 * matrix.A[2].s0 ) * matrix.A[3].s2;
  float d1 = ( d02 * matrix.A[2].s3 - d03 * matrix.A[2].s2 + d23 * matrix.A[2].s0 ) * matrix.A[3].s1;
  float d0 = ( d12 * matrix.A[2].s3 - d13 * matrix.A[2].s2 + d23 * matrix.A[2].s1 ) * matrix.A[3].s0;
  return d3 - d2 + d1 - d0;
}

