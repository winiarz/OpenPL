#ifndef __I_CL_KERNEL_MANAGER__
#define __I_CL_KERNEL_MANAGER__

#include "boost.hpp"

class IClKernel;

class IClKernelManager
{
public:
    virtual void loadKernel( IClKernel* kernel) = 0;
};

#endif
