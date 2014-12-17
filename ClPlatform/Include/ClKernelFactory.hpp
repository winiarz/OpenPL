#pragma once

#include "IClKernelFactory.hpp"

class ClKernelFactory : public IClKernelFactory {
public:
  ClKernelFactory();
  virtual OPL::IClKernel* buildClKernel( std::string, std::string );
};

