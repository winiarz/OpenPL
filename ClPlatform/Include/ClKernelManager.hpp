#pragma once

#include "IClKernelManager.hpp"
#include "ClError.hpp"
#include "stl.hpp"

namespace OPL
{
class ClKernel;

typedef std::set<OPL::ClKernel*> KernelPtrSet;

class ClKernelManager : public IClKernelManager
{
public:
    virtual void loadKernel( OPL::ClKernel* kernel);
    ~ClKernelManager();
private:
     KernelPtrSet loadedKernels;

     void unloadOneKernel(bool& isPossibleToLoad);
};

}

