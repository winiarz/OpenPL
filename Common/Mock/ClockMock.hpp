#ifndef __CLOCK_MOCK__
#define __CLOCK_MOCK__

#include<IClock.hpp>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class ClockMock : public IClock {
public:
    MOCK_METHOD0(getUsec, uint());
    MOCK_METHOD0(getMsec, uint());
    MOCK_METHOD0(getSec,  uint());
};

#endif
