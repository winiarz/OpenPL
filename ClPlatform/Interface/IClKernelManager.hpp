#pragma once

namespace OPL
{
class ClKernel;

class IClKernelManager
{
public:
    virtual void loadKernel( ClKernel* kernel) = 0;
};

}

