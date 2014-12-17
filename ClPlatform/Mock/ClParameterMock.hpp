#pragma once

#include "gmock/gmock.h"
#include "IClParameter.hpp"

namespace OPL
{

class ClParameterMock : public IClParameter {
public:
    MOCK_METHOD1( isCorrect, bool(int) );
    MOCK_METHOD0( getAllPosible, set<int> () );
};

}

