#pragma once
#include <string>

namespace OPL
{
class IClKernel;

class IClKernelFactory {
public:
  virtual IClKernel* buildClKernel( std::string, std::string )=0;
};

}

