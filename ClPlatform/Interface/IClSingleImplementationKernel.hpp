#pragma once

#include "IClKernel.hpp"

class IClSingleImplementationKernel : public IClKernel
{
public:
    virtual cl_program getProgram() = 0;
};

