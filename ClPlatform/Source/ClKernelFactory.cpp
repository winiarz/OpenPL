#include "ClKernelFactory.hpp"
#include <iostream>
ClKernelFactory::ClKernelFactory()
{ 
}

IClKernel* ClKernelFactory::buildClKernel( std::string fileName, std::string kernelName )
{
  return new ClKernel( fileName.c_str(), kernelName.c_str() );
}
