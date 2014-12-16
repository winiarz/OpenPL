#include<gtest/gtest.h>

#include"ClPlatform.hpp"

namespace OPL
{

class ClPlatformTestSuite : public ::testing::Test {
public:
  ClPlatformTestSuite();
protected:
  ClPlatform& sut;
};

ClPlatformTestSuite::ClPlatformTestSuite() : sut( ClPlatform::getPlatform() )
{
}

TEST_F(ClPlatformTestSuite, create_context)
{
  ASSERT_TRUE( sut.isSetUpSuccessfully() );
}

}

