#pragma once
#include <CL/cl.h>
#include "IClKernel.hpp"

namespace OPL
{

class IClSingleImplementationKernel : public IClKernel
{
public:
    virtual cl_program getProgram() = 0;
};

}

