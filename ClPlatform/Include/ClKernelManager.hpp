#pragma once

#include "IClKernelManager.hpp"
#include "ClError.hpp"
#include "stl.hpp"

class ClKernel;
typedef std::set<ClKernel*> KernelPtrSet;

class ClKernelManager : public IClKernelManager
{
public:
    virtual void loadKernel( ClKernel* kernel);
    ~ClKernelManager();
private:
     KernelPtrSet loadedKernels;

     void unloadOneKernel(bool& isPossibleToLoad);
};

