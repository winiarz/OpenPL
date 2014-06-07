#pragma once

#include "gmock/gmock.h"
#include "ClKernelFactory.hpp"

class ClKernelFactoryMock : public ClKernelFactory {
public:
  ClKernelFactoryMock(){}
  MOCK_METHOD2( buildClKernel, IClKernel*( std::string, std::string ) );
};

