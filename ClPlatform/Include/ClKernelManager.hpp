#pragma once
#include <set>
#include "IClKernelManager.hpp"

namespace OPL
{
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

}

