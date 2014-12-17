#include "ClKernelPerformanceComparator.hpp"
#include "ClSingleImplementationKernelMock.hpp"
#include "ClDataGeneratorMock.hpp"
#include "ClParameterizedKernelMock.hpp"
#include "ClockMock.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>

namespace OPL
{

using namespace ::testing;

class ClKernelPerformanceComparatorTestSuite : public Test {
public:
    ClKernelPerformanceComparatorTestSuite();
    void setDataGenerator();
    shared_ptr<ClSingleImplementationKernelMock> addKernel();
    shared_ptr<ClSingleImplementationKernelMock> addAndTestKernel(int workTime);
    shared_ptr<ClSingleImplementationKernelMock> expectGetKernel(shared_ptr<ClParameterizedKernelMock> paramKernelMock,
                                                                      int param);

    shared_ptr<ClockMock> clockMock;
    shared_ptr<ClDataGeneratorMock> dataGeneratorMock;
    shared_ptr<ClKernelPerformanceComparator> sut;
};

ClKernelPerformanceComparatorTestSuite::ClKernelPerformanceComparatorTestSuite() :
    clockMock(make_shared<ClockMock>()),
    dataGeneratorMock(make_shared<ClDataGeneratorMock>()),
    sut(make_shared<ClKernelPerformanceComparator>(*clockMock))
{
}

shared_ptr<ClSingleImplementationKernelMock> ClKernelPerformanceComparatorTestSuite::addKernel()
{
    auto kernelMock = make_shared<ClSingleImplementationKernelMock>();
    sut->addKernel( kernelMock );
    EXPECT_CALL( *kernelMock, Die());

    return kernelMock;
}

void ClKernelPerformanceComparatorTestSuite::setDataGenerator()
{
    sut->setDataGenerator(dataGeneratorMock);
    vector<shared_ptr<ClMemory> > data;
    EXPECT_CALL( *dataGeneratorMock, getData() ).WillRepeatedly(Return(data));
}

shared_ptr<ClSingleImplementationKernelMock> ClKernelPerformanceComparatorTestSuite::addAndTestKernel(int workTime)
{
    shared_ptr<ClSingleImplementationKernelMock> kernelMock = addKernel();

    EXPECT_CALL( *clockMock, getUsec()).WillOnce(Return(0)).WillOnce(Return(workTime));
    sut->comparationStep();

    return kernelMock;
}

shared_ptr<ClSingleImplementationKernelMock> ClKernelPerformanceComparatorTestSuite::expectGetKernel(shared_ptr<ClParameterizedKernelMock> paramKernelMock,
                                                                                        int param)
{
    shared_ptr<ClSingleImplementationKernelMock> kernelMock
        = make_shared<ClSingleImplementationKernelMock>();
    EXPECT_CALL( *kernelMock, Die());

    optional<shared_ptr<IClSingleImplementationKernel> > optionalKernel
        = shared_ptr<IClSingleImplementationKernel>(kernelMock);
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
    shared_ptr<ClSingleImplementationKernelMock> kernelMock = addKernel();

    optional<shared_ptr<IClSingleImplementationKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, kernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, firstKernelIsBetterUntilItisTested )
{
    shared_ptr<ClSingleImplementationKernelMock> firstKernelMock = addKernel();
    shared_ptr<ClSingleImplementationKernelMock> secondKernelMock = addKernel();

    optional<shared_ptr<IClSingleImplementationKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, firstKernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, kernelWithShorterTimeIsBetter )
{
    setDataGenerator();

    shared_ptr<ClSingleImplementationKernelMock> firstKernelMock = addAndTestKernel(100);
    shared_ptr<ClSingleImplementationKernelMock> secondKernelMock = addAndTestKernel(60);

    optional<shared_ptr<IClSingleImplementationKernel> > result = sut->getBestKernel();

    ASSERT_TRUE( result );
    ASSERT_EQ( *result, secondKernelMock );
}

TEST_F( ClKernelPerformanceComparatorTestSuite, addParametrizedKernelAddsKernelForAllParameters )
{
    auto paramKernelMock = make_shared<ClParameterizedKernelMock>();

    auto params = make_shared<set<int> >();
    params->insert(1);
    params->insert(2);
    EXPECT_CALL( *paramKernelMock, getNotRejectedParameters() ).WillOnce(Return(params));

    shared_ptr<ClSingleImplementationKernelMock> firstKernel = expectGetKernel( paramKernelMock, 1 );
    shared_ptr<ClSingleImplementationKernelMock> secondKernel = expectGetKernel( paramKernelMock, 2 );

    sut->addParameterizedKernel(paramKernelMock);
}

}

