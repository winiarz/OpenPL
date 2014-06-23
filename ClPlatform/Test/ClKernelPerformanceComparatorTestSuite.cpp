#include "ClKernelPerformanceComparator.hpp"
#include "ClSingleImplementationKernelMock.hpp"
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
    std::shared_ptr<ClSingleImplementationKernelMock> addKernel();
    std::shared_ptr<ClSingleImplementationKernelMock> addAndTestKernel(int workTime);
    std::shared_ptr<ClSingleImplementationKernelMock> expectGetKernel(boost::shared_ptr<ClParameterizedKernelMock> paramKernelMock,
                                                                      int param);

    boost::shared_ptr<ClockMock> clockMock;
    std::shared_ptr<ClDataGeneratorMock> dataGeneratorMock;
    boost::shared_ptr<ClKernelPerformanceComparator> sut;
};

ClKernelPerformanceComparatorTestSuite::ClKernelPerformanceComparatorTestSuite() :
    clockMock(make_shared<ClockMock>()),
    dataGeneratorMock(std::make_shared<ClDataGeneratorMock>()),
    sut(make_shared<ClKernelPerformanceComparator>(*clockMock))
{
}

std::shared_ptr<ClSingleImplementationKernelMock> ClKernelPerformanceComparatorTestSuite::addKernel()
{
    auto kernelMock = std::make_shared<ClSingleImplementationKernelMock>();
    sut->addKernel( kernelMock );
    EXPECT_CALL( *kernelMock, Die());

    return kernelMock;
}

void ClKernelPerformanceComparatorTestSuite::setDataGenerator()
{
    sut->setDataGenerator(dataGeneratorMock);
    vector<std::shared_ptr<ClMemory> > data;
    EXPECT_CALL( *dataGeneratorMock, getData() ).WillRepeatedly(Return(data));
}

std::shared_ptr<ClSingleImplementationKernelMock> ClKernelPerformanceComparatorTestSuite::addAndTestKernel(int workTime)
{
    std::shared_ptr<ClSingleImplementationKernelMock> kernelMock = addKernel();

    EXPECT_CALL( *clockMock, getUsec()).WillOnce(Return(0)).WillOnce(Return(workTime));
    sut->comparationStep();

    return kernelMock;
}

std::shared_ptr<ClSingleImplementationKernelMock> ClKernelPerformanceComparatorTestSuite::expectGetKernel(boost::shared_ptr<ClParameterizedKernelMock> paramKernelMock,
                                                                                        int param)
{
    std::shared_ptr<ClSingleImplementationKernelMock> kernelMock
        = std::make_shared<ClSingleImplementationKernelMock>();
    EXPECT_CALL( *kernelMock, Die());

    optional<std::shared_ptr<IClSingleImplementationKernel> > optionalKernel
        = std::shared_ptr<IClSingleImplementationKernel>(kernelMock);
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
    std::shared_ptr<ClSingleImplementationKernelMock> kernelMock = addKernel();

    optional<std::shared_ptr<IClSingleImplementationKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, kernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, firstKernelIsBetterUntilItisTested )
{
    std::shared_ptr<ClSingleImplementationKernelMock> firstKernelMock = addKernel();
    std::shared_ptr<ClSingleImplementationKernelMock> secondKernelMock = addKernel();

    optional<std::shared_ptr<IClSingleImplementationKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, firstKernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, kernelWithShorterTimeIsBetter )
{
    setDataGenerator();

    std::shared_ptr<ClSingleImplementationKernelMock> firstKernelMock = addAndTestKernel(100);
    std::shared_ptr<ClSingleImplementationKernelMock> secondKernelMock = addAndTestKernel(60);

    optional<std::shared_ptr<IClSingleImplementationKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, secondKernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, addParametrizedKernelAddsKernelForAllParameters )
{
    boost::shared_ptr<ClParameterizedKernelMock> paramKernelMock = boost::make_shared<ClParameterizedKernelMock>();

    auto params = std::make_shared<set<int> >();
    params->insert(1);
    params->insert(2);
    EXPECT_CALL( *paramKernelMock, getNotRejectedParameters() ).WillOnce(Return(params));

    std::shared_ptr<ClSingleImplementationKernelMock> firstKernel = expectGetKernel( paramKernelMock, 1 );
    std::shared_ptr<ClSingleImplementationKernelMock> secondKernel = expectGetKernel( paramKernelMock, 2 );

    sut->addParameterizedKernel(paramKernelMock);
}

