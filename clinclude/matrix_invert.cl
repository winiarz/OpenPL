
#include "matrix_determinant.cl"

float16 invert_matrix3x3(float16 A)
{
  float16 result;
  result.s0 = A.s5 * A.sa - A.s9 * A.s6;
  result.s1 = A.s2 * A.s9 - A.s1 * A.sa;
  result.s2 = A.s4 * A.s9 - A.s5 * A.s8;
  
  result.s4 = A.s6 * A.s8 - A.s4 * A.sa;
  result.s5 = A.s0 * A.sa - A.s2 * A.s8;
  result.s6 = A.s4 * A.s2 - A.s0 * A.s6;
  
  result.s8 = A.s4 * A.s9 - A.s5 * A.s8;
  result.s9 = A.s1 * A.s8 - A.s0 * A.s9;
  result.sa = A.s0 * A.s5 - A.s1 * A.s4;
  result /= matrix_determinant_3x3(A);
  return result;
}
