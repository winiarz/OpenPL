#include <iostream>
#include <gtest/gtest.h>
using namespace std;
#include "TestMatrixOperationsSim.hpp"
#include <math.h>
class Matrix4x4TS : public ::testing::Test {
public:
  MatrixOperationSim sim;
};

TEST_F(Matrix4x4TS, add_matrices)
{
  LocalMatrix4x4 A( 1, 2, 3, 4,
		    0, 1, 2, 3,
		    0, 1, 0, 1,
		    4, 3, 2, 1 );
  sim.matrices.copyIn(&A,1,1);
  LocalMatrix4x4 B( -1, -2, -3, -4,
		    0, 1, 2, 3,
		    0, -1, 0, 1,
		    4, -3, -2, 1 );
  sim.matrices.copyIn(&B,2,1);
  sim.add(sim.matrices);
  LocalMatrix4x4 C;
  sim.matrices.copyOut(&C,0,1);
  LocalMatrix4x4 D = A + B;
  ASSERT_TRUE( C == D );
}

TEST_F(Matrix4x4TS, multiply_matrices )
{
  LocalMatrix4x4 A( 1, 2, 3, 4,
		    0, 1, 2, 3,
		    0, 1, 0, 1,
		    4, 3, 2, 1 );
  sim.matrices.copyIn(&A,1,1);
  LocalMatrix4x4 B( -1, -2, -3, -4,
		    0, 1, 2, 3,
		    0, -1, 0, 1,
		    4, -3, -2, 1 );
  sim.matrices.copyIn(&B,2,1);  
  sim.multiply(sim.matrices);
  LocalMatrix4x4 C;
  sim.matrices.copyOut(&C,0,1);
  LocalMatrix4x4 D = A * B;
  ASSERT_TRUE( C == D );
}

TEST_F(Matrix4x4TS, multiply_by_scalar )
{
  LocalMatrix4x4 A( 1, 2, 3, 4,
		    0, 1, 2, 3,
		    0, 1, 0, 1,
		    4, 3, 2, 1 );
  sim.matrices.copyIn(&A,1,1);
  sim.multiply_by_scalar(sim.matrices);
  LocalMatrix4x4 C;
  sim.matrices.copyOut(&C,0,1);
  LocalMatrix4x4 D = scalar * A;
  ASSERT_TRUE( C == D );
}

TEST_F(Matrix4x4TS, determinant )
{
  LocalMatrix4x4 A( 1, 2, 3, 4,
		   -2, 1, 2, 3,
		   -3, 1, 3, 1,
		    4, 3, 2, -1 );
  sim.matrices.copyIn(&A,0,1);
  sim.determinant( sim.matrices, sim.result );
  
  float det;
  sim.result.copyOut(&det,0,1);
  ASSERT_FLOAT_EQ( det, -48.0);
}

class Matrix3x3TS : public ::testing::Test {
public:
  MatrixOperationSim sim;
};

TEST_F(Matrix3x3TS, add_matrices)
{
  LocalMatrix3x3 A( 1, 2, 3,
		    1, 5, 2,
		    3, 4, 2 );
  sim.matrices2.copyIn(&A,1,1);
  LocalMatrix3x3 B( 1, 3, 1,
		    1, 5, -2,
		    1, 4, 5 );
  sim.matrices2.copyIn(&B,2,1);  
  
  sim.add3x3( sim.matrices2 );
  
  LocalMatrix3x3 C;
  sim.matrices2.copyOut(&C,0,1);
  LocalMatrix3x3 D = A + B;
  ASSERT_TRUE( C == D );
}

TEST_F(Matrix3x3TS, multiply_matrices)
{
  LocalMatrix3x3 A( 1, 2, 3,
		    1, 5, 2,
		    3, 4, 2 );
  sim.matrices2.copyIn(&A,1,1);
  LocalMatrix3x3 B( 1, 3, 1,
		    1, 5, -2,
		    1, 4, 5 );
  sim.matrices2.copyIn(&B,2,1);  
  
  sim.mult3x3( sim.matrices2 );
  
  LocalMatrix3x3 C;
  sim.matrices2.copyOut(&C,0,1);
  LocalMatrix3x3 D = A * B;
  ASSERT_TRUE( C == D );
}

TEST_F(Matrix3x3TS, determinant )
{
  LocalMatrix3x3 A( 1, 2, 3,
		    1, 5, 2,
		    3, 4, 2 );
  sim.matrices2.copyIn(&A,0,1);
  sim.determinant3x3( sim.matrices2, sim.result );
  
  float det;
  sim.result.copyOut(&det,0,1);
  ASSERT_FLOAT_EQ( det, -23.0);
}

TEST_F(Matrix3x3TS, invert_3x3)
{
    LocalMatrix3x3 A( 1, 2, 3,
		    1, 1, 2,
		    3, 4, 2 );
    sim.matrices2.copyIn(&A,0,3);
    sim.invert_3x3( sim.matrices2 );
    sim.matrices2.copyOut(&A,2,1);
    LocalMatrix3x3 I( 1,0,0,
		      0,1,0,
		      0,0,1 );
    
    ASSERT_TRUE( A == I );
}
