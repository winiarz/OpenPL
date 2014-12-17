#pragma once

#include<IClParameterizedKernel.hpp>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

namespace OPL
{

class ClParameterizedKernelMock : public IClParameterizedKernel {
public:
    MOCK_METHOD1( getKernel, optional<shared_ptr<IClSingleImplementationKernel> >(int) );
    MOCK_METHOD1( rejectKernel, void (shared_ptr<IClSingleImplementationKernel>) );
    MOCK_METHOD0( getParameter, shared_ptr<IClParameter> () );
    MOCK_METHOD0( getNotRejectedParameters, shared_ptr<set<int> > () );
};

}

