#pragma once

namespace OPL
{
class ClKernel;

class IClKernelManager
{
public:
    virtual void loadKernel( OPL::ClKernel* kernel) = 0;
};

}

