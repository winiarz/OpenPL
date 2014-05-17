#include "ClKernelCallStats.hpp"

ClKernelCallStats::ClKernelCallStats(boost::shared_ptr<IClock> p_clock,
                                     float p_forgetParameter) :
            clock(p_clock),
            score(0.0f),
            lastCallTime(0),
            forgetParameter(p_forgetParameter)
{
}

float ClKernelCallStats::getScore()
{
    return score;
}

void ClKernelCallStats::registerCall()
{
    uint newLastCallTime = clock->getUsec();
    score = forgetParameter * score + 1000000.0 / float(newLastCallTime - lastCallTime);
    lastCallTime = newLastCallTime;
}
