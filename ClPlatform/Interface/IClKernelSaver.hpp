#ifndef __I_CL_KERNEL_SAVER__
#define __I_CL_KERNEL_SAVER__

#include "stl.hpp"
#include "boost.hpp"
class ClKernel;

class IClKernelSaver
{
public:
    virtual void saveKernel( boost::shared_ptr<ClKernel> kernel, std::string filename ) = 0;
};

#endif
