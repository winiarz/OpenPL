#ifndef __CL_KERNEL_MANAGER__
#define __CL_KERNEL_MANAGER__

#include "IClKernelManager.hpp"
#include "IClKernel.hpp"
#include "ClError.hpp"
#include "stl.hpp"

//typedef std::set<boost::shared_ptr<IClKernel> > KernelPtrSet;
typedef std::set<IClKernel*> KernelPtrSet;

class ClKernelManager : public IClKernelManager
{
public:
    virtual void loadKernel( IClKernel* kernel);
    ~ClKernelManager();
private:
     KernelPtrSet loadedKernels;

     void unloadOneKernel(bool& isPossibleToLoad);
};

#endif

