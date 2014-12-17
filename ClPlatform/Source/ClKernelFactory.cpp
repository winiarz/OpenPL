#include "ClKernelFactory.hpp"
#include <iostream>
ClKernelFactory::ClKernelFactory()
{ 
}

OPL::IClKernel* ClKernelFactory::buildClKernel( std::string fileName, std::string kernelName )
{
  return new OPL::ClKernel( fileName.c_str(), kernelName.c_str() );
}
