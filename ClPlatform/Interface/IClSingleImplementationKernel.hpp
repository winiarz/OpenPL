#pragma once

#include "IClKernel.hpp"

class IClSingleImplementationKernel : public OPL::IClKernel
{
public:
    virtual cl_program getProgram() = 0;
};

