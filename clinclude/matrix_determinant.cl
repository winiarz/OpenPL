
float matrix_determinant_4x4(float16 matrix)
{
  float d01 = matrix.s0 * matrix.s5 - matrix.s1 * matrix.s4;
  float d02 = matrix.s0 * matrix.s6 - matrix.s2 * matrix.s4;
  float d03 = matrix.s0 * matrix.s7 - matrix.s3 * matrix.s4;
  float d12 = matrix.s1 * matrix.s6 - matrix.s2 * matrix.s5;
  float d13 = matrix.s1 * matrix.s7 - matrix.s3 * matrix.s5;
  float d23 = matrix.s2 * matrix.s7 - matrix.s3 * matrix.s6;
  
  float d3 = ( d01 * matrix.sA - d02 * matrix.s9 + d12 * matrix.s8 ) * matrix.sF;
  float d2 = ( d01 * matrix.sB - d03 * matrix.s9 + d13 * matrix.s8 ) * matrix.sE;
  float d1 = ( d02 * matrix.sB - d03 * matrix.sA + d23 * matrix.s8 ) * matrix.sD;
  float d0 = ( d12 * matrix.sB - d13 * matrix.sA + d23 * matrix.s9 ) * matrix.sC;
  return d3 - d2 + d1 - d0;
}

float matrix_determinant_3x3(float16 matrix)
{
  float d0 = matrix.s0 * (matrix.s5 * matrix.sA - matrix.s6 * matrix.s9);
  float d1 = matrix.s1 * (matrix.s4 * matrix.sA - matrix.s6 * matrix.s8);
  float d2 = matrix.s2 * (matrix.s4 * matrix.s9 - matrix.s5 * matrix.s8);
  return d0 - d1 + d2;
}
