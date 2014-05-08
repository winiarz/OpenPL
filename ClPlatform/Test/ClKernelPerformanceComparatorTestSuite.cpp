#include "ClKernelPerformanceComparator.hpp"
#include "ClKernelMock.hpp"
#include "ClDataGeneratorMock.hpp"
#include "ClParameterizedKernelMock.hpp"
#include "ClockMock.hpp"
#include "boost.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace ::testing;

class ClKernelPerformanceComparatorTestSuite : public Test {
public:
    ClKernelPerformanceComparatorTestSuite();
    void setDataGenerator();
    boost::shared_ptr<ClKernelMock> addKernel();
    boost::shared_ptr<ClKernelMock> addAndTestKernel(int workTime);
    boost::shared_ptr<ClKernelMock> expectGetKernel(boost::shared_ptr<ClParameterizedKernelMock> paramKernelMock,
                                                    int param);

    boost::shared_ptr<ClockMock> clockMock;
    boost::shared_ptr<ClDataGeneratorMock> dataGeneratorMock;
    boost::shared_ptr<ClKernelPerformanceComparator> sut;
};

ClKernelPerformanceComparatorTestSuite::ClKernelPerformanceComparatorTestSuite() :
    clockMock(make_shared<ClockMock>()),
    dataGeneratorMock(make_shared<ClDataGeneratorMock>()),
    sut(make_shared<ClKernelPerformanceComparator>(*clockMock))
{
}

boost::shared_ptr<ClKernelMock> ClKernelPerformanceComparatorTestSuite::addKernel()
{
    boost::shared_ptr<ClKernelMock> kernelMock = boost::make_shared<ClKernelMock>();
    sut->addKernel( kernelMock );
    EXPECT_CALL( *kernelMock, Die());

    return kernelMock;
}

void ClKernelPerformanceComparatorTestSuite::setDataGenerator()
{
    sut->setDataGenerator(dataGeneratorMock);
    vector<boost::shared_ptr<ClMemory> > data;
    EXPECT_CALL( *dataGeneratorMock, getData() ).WillRepeatedly(Return(data));
}

boost::shared_ptr<ClKernelMock> ClKernelPerformanceComparatorTestSuite::addAndTestKernel(int workTime)
{
    boost::shared_ptr<ClKernelMock> kernelMock = addKernel();

    EXPECT_CALL( *clockMock, getUsec()).WillOnce(Return(0)).WillOnce(Return(workTime));
    sut->comparationStep();

    return kernelMock;
}

boost::shared_ptr<ClKernelMock> ClKernelPerformanceComparatorTestSuite::expectGetKernel(boost::shared_ptr<ClParameterizedKernelMock> paramKernelMock,
                                                                                        int param)
{
    boost::shared_ptr<ClKernelMock> kernelMock = boost::make_shared<ClKernelMock>();
    EXPECT_CALL( *kernelMock, Die());

    optional<boost::shared_ptr<IClKernel> > optionalKernel = boost::shared_ptr<IClKernel>(kernelMock);
    EXPECT_CALL( *paramKernelMock, getKernel(param)).WillOnce(Return(optionalKernel));

    return kernelMock;
}

TEST_F( ClKernelPerformanceComparatorTestSuite, comparationStepWithoutDataGenerator)
{
    ASSERT_FALSE( sut->comparationStep() );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, getBestDataWithoutSettingKernel )
{
    ASSERT_FALSE( sut->getBestKernel() );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, onlyOneKernelisBestOne )
{
    boost::shared_ptr<ClKernelMock> kernelMock = addKernel();

    optional<boost::shared_ptr<IClKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, kernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, firstKernelIsBetterUntilItisTested )
{
    boost::shared_ptr<ClKernelMock> firstKernelMock = addKernel();
    boost::shared_ptr<ClKernelMock> secondKernelMock = addKernel();

    optional<boost::shared_ptr<IClKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, firstKernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, kernelWithShorterTimeIsBetter )
{
    setDataGenerator();

    boost::shared_ptr<ClKernelMock> firstKernelMock = addAndTestKernel(100);
    boost::shared_ptr<ClKernelMock> secondKernelMock = addAndTestKernel(60);

    optional<boost::shared_ptr<IClKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, secondKernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, addParametrizedKernelAddsKernelForAllParameters )
{
    boost::shared_ptr<ClParameterizedKernelMock> paramKernelMock = make_shared<ClParameterizedKernelMock>();

    boost::shared_ptr<set<int> > params = make_shared<set<int> >();
    params->insert(1);
    params->insert(2);
    EXPECT_CALL( *paramKernelMock, getNotRejectedParameters() ).WillOnce(Return(params));

    boost::shared_ptr<ClKernelMock> firstKernel = expectGetKernel( paramKernelMock, 1 );
    boost::shared_ptr<ClKernelMock> secondKernel = expectGetKernel( paramKernelMock, 2 );

    sut->addParameterizedKernel(paramKernelMock);
}

