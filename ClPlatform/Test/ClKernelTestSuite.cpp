#include <gtest/gtest.h>
#include "stl.hpp"
#include "ClKernel.hpp"

namespace OPL
{

class ClKernelTestSuite : public ::testing::Test {
public:
 ClKernelTestSuite(); 
protected:
  shared_ptr<ClKernel> sut;
  ClPlatform& platform;
};

ClKernelTestSuite::ClKernelTestSuite() : platform(ClPlatform::getPlatform())
{
}

TEST_F(ClKernelTestSuite, load_empty_kernel)
{
  sut = make_shared<ClKernel>("ClPlatform/TestData/empty.clbin","empty");

  ASSERT_TRUE( sut->isSetUpSuccessfully() );
}

TEST_F(ClKernelTestSuite, execute_empty_kernel)
{
  sut = make_shared<ClKernel>("ClPlatform/TestData/empty.clbin","empty");
  ASSERT_TRUE( sut->isSetUpSuccessfully() );
  
  (*sut)[1][1](0);
}

TEST_F(ClKernelTestSuite, execute_kernel_2_times)
{
  sut = make_shared<ClKernel>("ClPlatform/TestData/empty.clbin","empty");
  ASSERT_TRUE( sut->isSetUpSuccessfully() );
  (*sut)[1][1](0);
  ASSERT_TRUE( sut->isSetUpSuccessfully() );
  (*sut)[1][1](0);
}

TEST_F(ClKernelTestSuite, no_kernel_size_exception)
{
  sut = make_shared<ClKernel>("ClPlatform/TestData/empty.clbin","empty");
  ASSERT_TRUE( sut->isSetUpSuccessfully() ); 

  ASSERT_THROW( (*sut)(0),ClError ); 
}

}

