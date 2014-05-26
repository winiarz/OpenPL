#ifndef __I_CL_SINGLE_IMPLEMENTATION_KERNEL__
#define __I_CL_SINGLE_IMPLEMENTATION_KERNEL__

#include "IClKernel.hpp"

class IClSingleImplementationKernel : public IClKernel
{
public:
    virtual cl_program getProgram() = 0;
};

#endif
