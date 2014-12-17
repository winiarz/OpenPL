#pragma once

#include <string>
#include "ClKernel.hpp"

namespace OPL
{

class IClKernelFactory {
public:
  virtual OPL::IClKernel* buildClKernel( std::string, std::string )=0;
};

}

