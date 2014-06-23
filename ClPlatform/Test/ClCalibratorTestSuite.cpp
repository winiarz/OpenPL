#include "ClCalibrator.hpp"
#include "ClKernelPerformanceComparatorMock.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class ClCalibratorTestSuite : public Test {
public:
    ClCalibratorTestSuite();
    std::shared_ptr<ClKernelPerformanceComparatorMock> performanceComparatorMock1;
    std::shared_ptr<ClKernelPerformanceComparatorMock> performanceComparatorMock2;
    boost::shared_ptr<ClCalibrator> sut;
};

ClCalibratorTestSuite::ClCalibratorTestSuite() :
    performanceComparatorMock1(std::make_shared<NiceMock<ClKernelPerformanceComparatorMock> >()),
    performanceComparatorMock2(std::make_shared<NiceMock<ClKernelPerformanceComparatorMock> >()),
    sut(boost::make_shared<ClCalibrator>())
{
}

TEST_F( ClCalibratorTestSuite, calibrationIsFinishedWhenNoComparatorsAdded)
{
    ASSERT_TRUE( sut->isCalibrationFinished() );
}

TEST_F( ClCalibratorTestSuite, calibrationNotFinishedWhenCalibrateNotRun )
{
    sut->addPerformanceComparator( performanceComparatorMock1 );
    ASSERT_FALSE( sut->isCalibrationFinished() );
}

TEST_F( ClCalibratorTestSuite, calibrationIsFinishedIfOnlyComparatorFinishes )
{
    sut->addPerformanceComparator( performanceComparatorMock1 );

    EXPECT_CALL( *performanceComparatorMock1, comparationStep() ).WillOnce(Return(false));
    ASSERT_TRUE( sut->calibrate() );

    ASSERT_TRUE( sut->isCalibrationFinished() );
}

TEST_F( ClCalibratorTestSuite, calibrationIsNotFinishedIfThereIsOneComparatorRemaining )
{
    sut->addPerformanceComparator( performanceComparatorMock1 );
    sut->addPerformanceComparator( performanceComparatorMock2 );

    ON_CALL( *performanceComparatorMock1, comparationStep() ).WillByDefault(Return(false));
    ON_CALL( *performanceComparatorMock2, comparationStep() ).WillByDefault(Return(false));

    ASSERT_FALSE( sut->calibrate() );
    ASSERT_FALSE( sut->isCalibrationFinished() );
}

TEST_F( ClCalibratorTestSuite, calibrationIsNotFinishedIfOnlyComparatorDoesNotFinish )
{
    sut->addPerformanceComparator( performanceComparatorMock1 );

    EXPECT_CALL( *performanceComparatorMock1, comparationStep() ).WillOnce(Return(true));
    ASSERT_FALSE( sut->calibrate() );

    ASSERT_FALSE( sut->isCalibrationFinished() );
}
