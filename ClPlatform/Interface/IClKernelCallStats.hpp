#ifndef __I_CL_KERNEL_CALL_STATS__
#define __I_CL_KERNEL_CALL_STATS__

class IClKernelCallStats
{
public:
    virtual void registerCall() = 0;
    virtual float getScore() = 0;
};

#endif
