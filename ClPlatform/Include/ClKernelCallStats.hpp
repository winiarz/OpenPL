#pragma once

#include "IClKernelCallStats.hpp"
#include "IClock.hpp"
#include "stl.hpp"

namespace OPL
{

class ClKernelCallStats : public IClKernelCallStats
{
public:
    ClKernelCallStats(shared_ptr<IClock> p_clock, float p_forgetParameter);
    virtual void registerCall();
    virtual float getScore();
private:
    shared_ptr<IClock> clock;
    float score;
    uint lastCallTime;
    const float forgetParameter;
};

}

