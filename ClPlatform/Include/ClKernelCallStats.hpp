#pragma once

#include "IClKernelCallStats.hpp"
#include "IClock.hpp"
#include "boost.hpp"

class ClKernelCallStats : public IClKernelCallStats
{
public:
    ClKernelCallStats(std::shared_ptr<IClock> p_clock, float p_forgetParameter);
    virtual void registerCall();
    virtual float getScore();
private:
    std::shared_ptr<IClock> clock;
    float score;
    uint lastCallTime;
    const float forgetParameter;
};

