#include <gtest/gtest.h>
#include "ClMemory.hpp"

namespace OPL
{

class ClMemoryTestSuite : public ::testing::Test {
public:
  ClMemoryTestSuite();
protected:
  shared_ptr<ClMemory> sut;
  ClPlatform& platform;
};

ClMemoryTestSuite::ClMemoryTestSuite() : platform(ClPlatform::getPlatform())
{
}

TEST_F(ClMemoryTestSuite, create_memory)
{
  const uint memorySize = 20;
  sut =  make_shared<ClMemory>(memorySize);
  ASSERT_TRUE( sut->isSetUpSuccessfully() );
}

TEST_F(ClMemoryTestSuite, copy_int_and_out)
{
  const uint memorySize = 20;
  sut =  make_shared<ClMemory>(memorySize);
  ASSERT_TRUE( sut->isSetUpSuccessfully() );
  int data [5] = { 1,1,2,3,5 };
  int data2[5] = { 9,0,0,0,8 };
  sut->copyIn (&data [0],0, 16);
  sut->copyOut(&data2[1],4, 12);
  for(int i=1;i<=3;i++)
    ASSERT_EQ( data[i], data2[i] );
  ASSERT_EQ(data2[0],9);
  ASSERT_EQ(data2[4],8);
}

TEST_F(ClMemoryTestSuite, correct_memory_size )
{
  const uint memorySize = 123;
  sut = make_shared<ClMemory>(memorySize);

  ASSERT_EQ( sut->getSize(), memorySize );
}

}

