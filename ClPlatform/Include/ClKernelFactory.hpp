#pragma once

#include "IClKernelFactory.hpp"

namespace OPL
{

class ClKernelFactory : public IClKernelFactory {
public:
  ClKernelFactory();
  virtual OPL::IClKernel* buildClKernel( std::string, std::string );
};

}

