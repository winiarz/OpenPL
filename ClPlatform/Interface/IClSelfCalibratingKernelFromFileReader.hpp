#ifndef __I_CL_SELF_CALIBRATING_KERNEL_FROM_FILE_READER__
#define __I_CL_SELF_CALIBRATING_KERNEL_FROM_FILE_READER__

#include "boost.hpp"
#include "stl.hpp"
#include "ClSelfCalibratingKernel.hpp"

class IClSelfCalibratingKernelFromFileReader
{
public:
    virtual boost::shared_ptr<ClSelfCalibratingKernel> read(std::string filename) = 0;
};

#endif

