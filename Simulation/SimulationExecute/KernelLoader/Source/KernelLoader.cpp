#include "KernelLoader.hpp"
#include "IClKernelFactory.hpp"

KernelLoader::KernelLoader(IClKernelFactory* newKernelFactory)
{
  kernelFactory = newKernelFactory;
  autoUnloadEnabled=false;
}

void KernelLoader::enableAutoUnload()
{
  autoUnloadEnabled=true;
}

void KernelLoader::disableAutoUnload()
{
  autoUnloadEnabled=false;
}

bool KernelLoader::isAutoUnloadEnabled()
{
  return autoUnloadEnabled;
}

IClKernel* KernelLoader::load( std::string fileName, std::string kernelName)
{
    IClKernel* kernel = NULL;

    try
    {
        kernel = kernelFactory->buildClKernel( fileName, kernelName );
    }
    catch(ClError error)
    {
        if( error == OUT_OF_RESOURCES && autoUnloadEnabled )
        {
            if( kernel != NULL )
                delete kernel;
            IClKernel* toRemove = *kernelSet.begin();
            if( toRemove != NULL )
                delete toRemove;
            kernelSet.erase( toRemove );

            kernel = tryToLoad( fileName, kernelName );
        }
    }

    if( kernel != NULL && kernel->isLoaded() )
    {
        kernelSet.insert(kernel);
        return kernel;
    }
    else
    {
        delete kernel;
        return NULL;
    }
}

IClKernel* KernelLoader::tryToLoad( std::string fileName, std::string kernelName )
{
   IClKernel* kernel = NULL;
   try
   {
       kernel = kernelFactory->buildClKernel( fileName, kernelName );
   }
   catch(ClError error)
   {
       if( kernel != NULL )
            delete kernel;
       return NULL;
   }

   if( ! kernel->isLoaded() )
   {
       delete kernel;
       return NULL;
   }

   return kernel;
}

void KernelLoader::unload( IClKernel* )
{
  
}
