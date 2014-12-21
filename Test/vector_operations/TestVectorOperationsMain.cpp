#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "TestVectorOperationsSim.hpp"

class VectorOperationsTS : public ::testing::Test {
protected:
  VectorOperationsSim sim;
};

TEST_F( VectorOperationsTS, vector_add )
{
  LocalInt3 loc_vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      loc_vectors[j][i] = i+3*j;
  
  sim.vectors.copyIn(loc_vectors,0,3);
  sim.vec_add( sim.vectors );
  sim.vectors.copyOut(loc_vectors,0,3);
  for(int i=0;i<3;i++)
    ASSERT_EQ( loc_vectors[1][i] + loc_vectors[2][i], loc_vectors[0][i] );
}

TEST_F( VectorOperationsTS, vector_sub )
{
  LocalInt3 loc_vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      loc_vectors[j][i] = i+3*j;
  sim.vectors.copyIn(loc_vectors,0,3);
  sim.vec_sub( sim.vectors );
  sim.vectors.copyOut(loc_vectors,0,3);
  for(int i=0;i<3;i++)
    ASSERT_EQ( loc_vectors[1][i] - loc_vectors[2][i], loc_vectors[0][i] );
}

TEST_F( VectorOperationsTS, vector_dot )
{
  LocalFloat3 loc_vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      loc_vectors[j][i] = i+3*j;
  float scalars[1] = { 0.0f };
  sim.vectors2.copyIn(loc_vectors,0,3);
  sim.vec_dot( sim.vectors2, sim.scalars );
  sim.scalars.copyOut(scalars,0,1);
  ASSERT_FLOAT_EQ( loc_vectors[0][0] * loc_vectors[1][0] + loc_vectors[0][1] * loc_vectors[1][1] + loc_vectors[0][2] * loc_vectors[1][2], scalars[0] );
}

TEST_F( VectorOperationsTS, vector_cross )
{
  LocalFloat3 vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      vectors[j][i] = i+3*j;
  sim.vectors2.copyIn( vectors, 0 , 3 );
  sim.vec_cross( sim.vectors2 );
  sim.vectors2.copyOut( vectors, 0, 3 );
  
  ASSERT_FLOAT_EQ( vectors[1][1] * vectors[2][2] - vectors[1][2] * vectors[2][1], vectors[0][0]);
  ASSERT_FLOAT_EQ( vectors[1][2] * vectors[2][0] - vectors[1][0] * vectors[2][2], vectors[0][1]);
  ASSERT_FLOAT_EQ( vectors[1][0] * vectors[2][1] - vectors[1][1] * vectors[2][0], vectors[0][2]);
}

TEST_F( VectorOperationsTS, vector_mult )
{
  LocalFloat3 vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      vectors[j][i] = i+3*j;
  float scalars[1] = { 3 };
  sim.vectors2.copyIn( vectors, 0, 2 );
  sim.scalars.copyIn( scalars, 0, 1 );
  sim.vec_mult( sim.vectors2, sim.scalars);
  sim.vectors2.copyOut( vectors, 0, 1 );
  for(int i=0;i<3;i++)
    ASSERT_FLOAT_EQ( vectors[1][i] * scalars[0], vectors[0][i]);
}

TEST_F( VectorOperationsTS, vector_mult2 )
{
  LocalFloat3 vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      vectors[j][i] = i+3*j;
  float scalars[1] = { 3 };
  sim.vectors2.copyIn( vectors, 0, 2 );
  sim.scalars.copyIn( scalars, 0, 1 );
  sim.vec_mult2( sim.vectors2, sim.scalars);
  sim.vectors2.copyOut( vectors, 0, 1 );
  for(int i=0;i<3;i++)
    ASSERT_FLOAT_EQ( vectors[1][i] * scalars[0], vectors[0][i]);
}

TEST_F( VectorOperationsTS, vector_div )
{
  LocalFloat3 vectors[3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      vectors[j][i] = i+3*j;
  float scalars[1] = { 3 };
  sim.vectors2.copyIn( vectors, 0, 2 );
  sim.scalars.copyIn( scalars, 0, 1 );
  sim.vec_div( sim.vectors2, sim.scalars);
  sim.vectors2.copyOut( vectors, 0, 1 );
  for(int i=0;i<3;i++)
    ASSERT_FLOAT_EQ( vectors[1][i] / scalars[0], vectors[0][i]);
}
