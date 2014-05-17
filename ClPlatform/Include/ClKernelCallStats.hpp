#ifndef __CL_KERNEL_CALL_STATS__
#define __CL_KERNEL_CALL_STATS__

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

#endif

