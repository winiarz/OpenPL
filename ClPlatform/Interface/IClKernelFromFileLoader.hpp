#ifndef __I_CL_KERNEL_FROM_FILE_LOADER__
#define __I_CL_KERNEL_FROM_FILE_LOADER__

#include "boost.hpp"
#include "stl.hpp"

class IClKernel;

class IClKernelFromFileLoader
{
public:
    virtual boost::shared_ptr<IClKernel> loadKernel(std::string filename) = 0;
};

#endif

