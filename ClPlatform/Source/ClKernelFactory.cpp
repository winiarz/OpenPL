#include "ClKernelFactory.hpp"
#include "ClKernel.hpp"
//#include <iostream>

namespace OPL
{

ClKernelFactory::ClKernelFactory()
{ 
}

IClKernel* ClKernelFactory::buildClKernel( std::string fileName, std::string kernelName )
{
  return new ClKernel( fileName.c_str(), kernelName.c_str() );
}

}

