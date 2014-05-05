
#ifndef __KERNEL_LOADER__
#define __KERNEL_LOADER__

#include <string>
#include "ClKernel.hpp"

class IKernelLoader {
public:
  virtual void enableAutoUnload()=0;
  virtual void disableAutoUnload()=0;
  virtual bool isAutoUnloadEnabled()=0;
  
  virtual IClKernel* load( std::string, std::string )=0;
  virtual void unload( IClKernel* )=0;
};

#endif
