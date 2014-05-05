#ifndef __CL_KERNEL_FACTORY__
#define __CL_KERNEL_FACTORY__

#include "IClKernelFactory.hpp"

class ClKernelFactory : public IClKernelFactory {
public:
  ClKernelFactory();
  virtual IClKernel* buildClKernel( std::string, std::string );
};

#endif
