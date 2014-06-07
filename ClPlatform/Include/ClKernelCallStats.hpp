#pragma once

#include "IClKernelCallStats.hpp"
#include "IClock.hpp"
#include "boost.hpp"

class ClKernelCallStats : public IClKernelCallStats
{
public:
    ClKernelCallStats(boost::shared_ptr<IClock> p_clock, float p_forgetParameter);
    virtual void registerCall();
    virtual float getScore();
private:
    boost::shared_ptr<IClock> clock;
    float score;
    uint lastCallTime;
    const float forgetParameter;
};

