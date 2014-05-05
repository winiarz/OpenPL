
#ifndef __I_KERNEL_LOADER__
#define __I_KERNEL_LOADER__

#include <set>

#include "IKernelLoader.hpp"
#include "ClKernelFactory.hpp"

class KernelLoader : IKernelLoader {
public:
  KernelLoader(IClKernelFactory*);
  
  void enableAutoUnload();
  void disableAutoUnload();
  bool isAutoUnloadEnabled();
  
  IClKernel* load( std::string, std::string );
  void unload( IClKernel* );
private:
  bool autoUnloadEnabled;
  IClKernelFactory* kernelFactory;

  IClKernel* tryToLoad( std::string, std::string );

  std::set<IClKernel*> kernelSet;
};

#endif
