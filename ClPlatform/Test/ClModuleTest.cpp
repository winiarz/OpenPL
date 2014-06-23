#include <gtest/gtest.h>

#include "ClPlatform.hpp"
#include "ClTypedMemory.hpp"
#include "ClKernel.hpp"

#include <iostream>
using namespace std;

class ClModuleTestSuite : public ::testing::Test {
public:
  ClModuleTestSuite();
  ClPlatform& platform;
};

ClModuleTestSuite::ClModuleTestSuite() : platform(ClPlatform::getPlatform())
{
}

TEST_F(ClModuleTestSuite, addition_kernel)
{
  ClTypedMemory<int> a(100), b(100), c(100);
  ClTypedMemory<int> size(1);
  ASSERT_FALSE( !a );
  ASSERT_FALSE( !b );
  ASSERT_FALSE( !c );
  ASSERT_FALSE( !size );
  int A[100],B[100],C[100];
  for(int i=0;i<100;i++)
  {
      A[i] = i%10;
      B[i] = i/10;
      C[i] = 0;
  }
  ClKernel addition( "ClPlatform/TestData/addition.clbin", "addition");
  ASSERT_FALSE( !addition );
  
  int hundred=100;
  
  a.copyIn (A,0,100);
  b.copyIn (B,0,100);
  size.copyIn(&hundred,0,1);
  
  ASSERT_NO_THROW( addition[1][1](4, &a, &b, &c, &size) );
  platform.execute();
  
  c.copyOut(C,0,100);
  for(int i=0;i<100;i++)
    ASSERT_EQ( C[i] , A[i] + B[i]);
}

TEST_F(ClModuleTestSuite, multithread_addition_kernel)
{
  ClTypedMemory<int> a(100), b(100), c(100);
  ClTypedMemory<int> size(1);
  ASSERT_FALSE( !a );
  ASSERT_FALSE( !b );
  ASSERT_FALSE( !c );
  ASSERT_FALSE( !size );
  int A[100],B[100],C[100];
  for(int i=0;i<100;i++)
  {
      A[i] = i%10;
      B[i] = i/10;
      C[i] = 0;
  }
  ClKernel addition( "ClPlatform/TestData/addition.clbin", "addition");
  ASSERT_FALSE( !addition );
  
  int hundred=100;
  
  a.copyIn (A,0,100);
  b.copyIn (B,0,100);
  size.copyIn(&hundred,0,1);
  
  ASSERT_NO_THROW( addition[platform.max_work_group_size][platform.max_work_group_size](4, &a, &b, &c, &size) );
  platform.execute();
  
  c.copyOut(C,0,100);
  for(int i=0;i<100;i++)
    ASSERT_EQ( C[i] , A[i] + B[i]);
}

