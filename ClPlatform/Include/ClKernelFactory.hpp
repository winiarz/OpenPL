#pragma once

#include "IClKernelFactory.hpp"

class ClKernelFactory : public IClKernelFactory {
public:
  ClKernelFactory();
  virtual IClKernel* buildClKernel( std::string, std::string );
};

