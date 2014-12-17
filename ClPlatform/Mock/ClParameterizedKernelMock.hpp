#pragma once

#include<IClParameterizedKernel.hpp>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class ClParameterizedKernelMock : public IClParameterizedKernel {
public:
    MOCK_METHOD1( getKernel, optional<shared_ptr<OPL::IClSingleImplementationKernel> >(int) );
    MOCK_METHOD1( rejectKernel, void (shared_ptr<OPL::IClSingleImplementationKernel>) );
    MOCK_METHOD0( getParameter, shared_ptr<IClParameter> () );
    MOCK_METHOD0( getNotRejectedParameters, shared_ptr<set<int> > () );
};

