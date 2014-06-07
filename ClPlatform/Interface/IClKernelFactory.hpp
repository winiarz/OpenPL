#pragma once

#include <string>
#include "ClKernel.hpp"

class IClKernelFactory {
public:
  virtual IClKernel* buildClKernel( std::string, std::string )=0;
};

