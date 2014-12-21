#pragma once

#include<IClock.hpp>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

namespace OPL
{

class ClockMock : public IClock {
public:
    MOCK_METHOD0(getUsec, uint());
    MOCK_METHOD0(getMsec, uint());
    MOCK_METHOD0(getSec,  uint());
};

}
