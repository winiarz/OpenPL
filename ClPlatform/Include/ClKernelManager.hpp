#ifndef __CL_KERNEL_MANAGER__
#define __CL_KERNEL_MANAGER__

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

#endif

