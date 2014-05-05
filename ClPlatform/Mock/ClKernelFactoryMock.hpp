#ifndef __CL_KERNEL_FACOTRY_MOCK__
#define __CL_KERNEL_FACOTRY_MOCK__

#include "gmock/gmock.h"
#include "ClKernelFactory.hpp"

class ClKernelFactoryMock : public ClKernelFactory {
public:
  ClKernelFactoryMock(){}
  MOCK_METHOD2( buildClKernel, IClKernel*( std::string, std::string ) );
};

#endif
