#ifndef __CL_PARAMETER_MOCK_HPP__
#define __CL_PARAMETER_MOCK_HPP__

#include "gmock/gmock.h"
#include "IClParameter.hpp"

class ClParameterMock : public IClParameter {
public:
    MOCK_METHOD1( isCorrect, bool(int) );
    MOCK_METHOD0( getAllPosible, set<int> () );
};

#endif

