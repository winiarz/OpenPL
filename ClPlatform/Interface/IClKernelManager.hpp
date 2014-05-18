#ifndef __I_CL_KERNEL_MANAGER__
#define __I_CL_KERNEL_MANAGER__

#include "boost.hpp"

class ClKernel;

class IClKernelManager
{
public:
    virtual void loadKernel( ClKernel* kernel) = 0;
};

#endif
