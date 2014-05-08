#include "ClKernelPerformanceComparator.hpp"
#include "ClockMock.hpp"
#include "boost.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace ::testing;

class ClKernelPerformanceComparatorTestSuite : public Test {
public:
    ClKernelPerformanceComparatorTestSuite();

    boost::shared_ptr<ClockMock> clockMock;
    boost::shared_ptr<ClKernelPerformanceComparator> sut;
};

ClKernelPerformanceComparatorTestSuite::ClKernelPerformanceComparatorTestSuite() :
    clockMock(make_shared<ClockMock>()),
    sut(make_shared<ClKernelPerformanceComparator>(*clockMock))
{
}

TEST_F(ClKernelPerformanceComparatorTestSuite, comparationStepWithoutDataGenerator)
{
    ASSERT_FALSE( sut->comparationStep() );
}
