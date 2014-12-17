#include <gtest/gtest.h>
#include <ClParameterizedKernelFromSource.hpp>
#include <ClParameterMock.hpp>

namespace OPL
{

using ::testing::StrictMock;
using ::testing::Return;

typedef shared_ptr<ClParameterizedKernel> ParametrizedKernelPtr;

class ClParameterizedKernelFromSourceTestSuite : public ::testing::Test {
public:
    ClParameterizedKernelFromSourceTestSuite() :
        validParameter(123),
        invalidParameter(321),
        parameterMock(make_shared<StrictMock<ClParameterMock> >())
    {
    }

    ParametrizedKernelPtr prepareSUT();
    void isParamCorrectExpectations();

    int validParameter;
    int invalidParameter;
    shared_ptr<ClParameterMock> parameterMock;
};

ParametrizedKernelPtr ClParameterizedKernelFromSourceTestSuite::prepareSUT()
{
    return make_shared<ClParameterizedKernelFromSource>(parameterMock,
                                                             string("ClPlatform/TestData/parametrized_kernel.cl"),
                                                             string("parameterized_kernel"),
                                                             string("$param$"));
}

void ClParameterizedKernelFromSourceTestSuite::isParamCorrectExpectations()
{
    EXPECT_CALL( *parameterMock, isCorrect(invalidParameter)).WillRepeatedly(Return(false));
    EXPECT_CALL( *parameterMock, isCorrect(validParameter)).WillRepeatedly(Return(true));
}

TEST_F(ClParameterizedKernelFromSourceTestSuite, returnsNoneWhenParameterIsInvalid)
{
    ParametrizedKernelPtr m_sut = prepareSUT();

    isParamCorrectExpectations();

    optional<shared_ptr<IClSingleImplementationKernel> > kernel = m_sut->getKernel(invalidParameter);
    ASSERT_EQ( none, kernel );
}

TEST_F(ClParameterizedKernelFromSourceTestSuite, returnsKernelWhenParameterIsValid)
{
    ParametrizedKernelPtr m_sut = prepareSUT();

    isParamCorrectExpectations();
    
    optional<shared_ptr<IClSingleImplementationKernel> > kernel = m_sut->getKernel(validParameter);
    ASSERT_TRUE( kernel );
}

TEST_F(ClParameterizedKernelFromSourceTestSuite, returnsNoneWhenKernelIsRejected)
{
    ParametrizedKernelPtr m_sut = prepareSUT();

    isParamCorrectExpectations();

    optional<shared_ptr<IClSingleImplementationKernel> > kernel = m_sut->getKernel(validParameter);

    m_sut->rejectKernel(*kernel);
    optional<shared_ptr<IClSingleImplementationKernel> > kernel2 = m_sut->getKernel(validParameter);

    ASSERT_EQ( none, kernel2 );
}

}
