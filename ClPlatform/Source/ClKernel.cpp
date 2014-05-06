#include <stdarg.h>
#include "ClKernel.hpp"
#include "ClMemory.hpp"
#include "logs.hpp"

ClKernel::ClKernel( const char fileName[], const char kernelName[] ) : platform(ClPlatform::getPlatform())
{
  program = CreateProgramFromBinary( platform.getContext(), platform.getDevice(), fileName );
  if( !program )
  {
      ERROR << "Error in creating program from file: " << fileName;
      setUpSuccessfully = false;
      return;
  }
  
  cl_int error;
  kernel = clCreateKernel( program, kernelName, &error );
  if( (!kernel) || (error != CL_SUCCESS) )
    {
      ERROR << "error in creating kernel OpenCL error = " << error;
      setUpSuccessfully = false;
      if( error == CL_OUT_OF_RESOURCES )
      {
          delete this;
          throw OUT_OF_RESOURCES;
      }
      return;
    }

  localSize = 0;
  globalSize = 0;

  setUpSuccessfully = true;
}

ClKernel::~ClKernel()
{
  clReleaseKernel(kernel);
}

bool ClKernel::isLoaded()
{
  return isSetUpSuccessfully();
}

bool ClKernel::isSetUpSuccessfully()
{
  return setUpSuccessfully;
}

bool ClKernel::operator!()
{
  return !isSetUpSuccessfully();
}

IClKernel& ClKernel::operator[](uint size)
{
  if( size <= 0 )
    return *this;

  if( globalSize <= 0 )
  {
    globalSize = size;
    return *this;
  }

  if( localSize <= 0 )
  {
    localSize = size;
    globalSize*=size;
    return *this;
  }
  
  return *this;
}

IClKernel& ClKernel::operator()(uint argumentNb, ...  )
{
  cl_int error;
  va_list li;
  va_start(li,argumentNb);

  for(uint i=0; i < argumentNb; i++)
  {
    ClMemory* memory = va_arg(li,ClMemory*);
    error = clSetKernelArg( kernel, i, sizeof(memory->memory), &(memory->memory) );
    if( error != CL_SUCCESS )
    {
        ERROR << "error in setting kernel arg argNb = " << i << "OpenCL error = " << error;
        throw KERNEL_SET_ARG_ERROR;
    }
  }
  va_end(li);
  if( (globalSize <= 0) || (localSize <= 0) )
  {
      ERROR << "running kernel without setting threads nb first";
      throw KERNEL_SIZE_NOT_SET; 
  }
  error = clEnqueueNDRangeKernel( platform.queue, kernel, 1, NULL,  &globalSize, &localSize, 0, NULL, NULL);
  if( error != CL_SUCCESS )
  {
      ERROR << "error in kernel execution OpenCL error = " << error;
      throw KERNEL_EXEC_ERROR;
  }
  platform.execute();
  
  return *this;
}

