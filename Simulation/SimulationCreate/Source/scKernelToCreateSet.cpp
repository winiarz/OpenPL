#include <iostream>
#include "scKernelToCreateSet.hpp"

using namespace OPL::SimCreate;

void KernelToCreateSet::addKernel(CreateKernel* newKernel)
{
  kernelsSet.insert(newKernel);
}

void KernelToCreateSet::createAllKernels()
{
  set<CreateKernel*>::iterator i;
  for(i = kernelsSet.begin(); i !=  kernelsSet.end(); i++)
  {
    std::cout << "kernel: " << (**i).getName() << std::endl;
    (**i).createKernel();
  }
}

KernelToCreateSet::KernelToCreateSet()
{
}

KernelToCreateSet& KernelToCreateSet::getKernelToCreateSet()
{
    static KernelToCreateSet onlyKernelSet;
    return onlyKernelSet;
}

bool KernelToCreateSet::loadKernel( ClKernel** kernel, std::string kernelName, std::string  fileName )
{
  if( *kernel != NULL && (*kernel)->isSetUpSuccessfully() )
    return true;
  
  *kernel = new ClKernel( CreateKernel::getBinaryFileName(fileName).c_str(), kernelName.c_str() );
  if( (*kernel)->isSetUpSuccessfully() )
    return true;
  
  set<CreateKernel*>::iterator i;
  for(i = kernelsSet.begin(); i !=  kernelsSet.end(); i++)
  {
    if( fileName.compare( (**i).getSourceFileName() ) == 0 )
    {
      (**i).createKernel();
      break;
    }
  }
  
  *kernel = new ClKernel( CreateKernel::getBinaryFileName(fileName).c_str(), kernelName.c_str() );  
  return (*kernel)->isSetUpSuccessfully();
}

void KernelToCreateSet::loadAndRunKernel0( ClKernel** kernel, std::string kernelName, std::string  fileName)
{
  if( loadKernel( kernel, kernelName, fileName ) )
  {
    (**kernel)[1][ClPlatform::getPlatform().max_work_group_size](0);
  }
  else
    std::cerr << "Unable to load kernel " << kernelName << std::endl;
}

void KernelToCreateSet::loadAndRunKernel1( ClKernel** kernel, std::string kernelName, std::string  fileName, ClMemory* arg1)
{
  if( loadKernel( kernel, kernelName, fileName ) )
  {
    (**kernel)[1][ClPlatform::getPlatform().max_work_group_size](1,arg1);
  }
  else
    std::cerr << "Unable to load kernel " << kernelName << std::endl;
}

void KernelToCreateSet::loadAndRunKernel2( ClKernel** kernel, std::string kernelName, std::string  fileName, ClMemory* arg1, ClMemory* arg2)
{
  if( loadKernel( kernel, kernelName, fileName ) )
  {
    (**kernel)[1][ClPlatform::getPlatform().max_work_group_size](2, arg1, arg2 );
  }
  else
    std::cerr << "Unable to load kernel " << kernelName << std::endl;
}
