#pragma once

#include<IClParameterizedKernel.hpp>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class ClParameterizedKernelMock : public IClParameterizedKernel {
public:
    MOCK_METHOD1( getKernel, optional<std::shared_ptr<IClSingleImplementationKernel> >(int) );
    MOCK_METHOD1( rejectKernel, void (std::shared_ptr<IClSingleImplementationKernel>) );
    MOCK_METHOD0( getParameter, std::shared_ptr<IClParameter> () );
    MOCK_METHOD0( getNotRejectedParameters, std::shared_ptr<set<int> > () );
};

