
float16 matrix_multiply4x4(float16 A, float16 B)
{
  float16 C1 = (float16)( A.s0 * B.lo.lo, A.s4 * B.lo.lo, A.s8*B.lo.lo, A.sC * B.lo.lo );
  float16 C2 = (float16)( A.s1 * B.lo.hi, A.s5 * B.lo.hi, A.s9*B.lo.hi, A.sD * B.lo.hi );
  float16 C3 = (float16)( A.s2 * B.hi.lo, A.s6 * B.hi.lo, A.sA*B.hi.lo, A.sE * B.hi.lo );
  float16 C4 = (float16)( A.s3 * B.hi.hi, A.s7 * B.hi.hi, A.sB*B.hi.hi, A.sF * B.hi.hi );
  return C1+C2+C3+C4;
}

float16 matrix_multiply3x3(float16 A,float16 B)
{
  float16 C1 = (float16)( A.s0 * B.lo.lo, A.s4 * B.lo.lo, A.s8*B.lo.lo, (float4)(0) );
  float16 C2 = (float16)( A.s1 * B.lo.hi, A.s5 * B.lo.hi, A.s9*B.lo.hi, (float4)(0) );
  float16 C3 = (float16)( A.s2 * B.hi.lo, A.s6 * B.hi.lo, A.sA*B.hi.lo, (float4)(0) );
  return C1+C2+C3;
}

float4 matrix_multiply2x2(float4 A,float4 B)
{
  float4 C1 = (float4)( A.s0 * B.lo, A.s2 * B.lo );
  float4 C2 = (float4)( A.s1 * B.hi, A.s3 * B.hi );
  return C1+C2;
}
