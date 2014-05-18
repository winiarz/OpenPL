#include <stdarg.h>
#include "ClKernel.hpp"
#include "ClMemory.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "Clock.hpp"
#include "logs.hpp"

ClKernel::ClKernel( const char fileName[], const char p_kernelName[] ) :
    platform(ClPlatform::getPlatform()),
    kernel(0),
    loaded(false),
    kernelName(p_kernelName),
    stats(boost::make_shared<Clock>(), 0.95f)
{
    setUpSuccessfully = false;
    try
    {
        boost::shared_ptr<ClKernel> tempKernel = ClKernelFromBinaryLoader().loadKernel(fileName);
        program = tempKernel->getProgram();
    }
    catch ( ClError error ) 
    {
        ERROR << "Error while loading kernel " << kernelName << " from file " << fileName;
        return;
    }

    if( !program )
    {
        ERROR << "Error in creating program from file: " << fileName;
        setUpSuccessfully = false;
        return;
    }

    localSize = 0;
    globalSize = 0;

    setUpSuccessfully = true;
}

ClKernel::ClKernel( cl_program p_program ) :
    platform(ClPlatform::getPlatform()),
    program(p_program),
    kernel(0),
    stats(boost::make_shared<Clock>(), 0.95f)
{
    setUpSuccessfully = false;
}

void ClKernel::load()
{
    cl_int error;
    kernel = clCreateKernel( program, kernelName.c_str(), &error );
    if( (!kernel) || (error != CL_SUCCESS) )
    {
        ERROR << "error in creating kernel OpenCL error = " << error;
        setUpSuccessfully = false;
        delete this;
        if( error == CL_OUT_OF_RESOURCES )
        {
            throw OUT_OF_RESOURCES;
        }
        else
        {
            throw OPEN_CL_ERROR;
        }
    }
    else
        loaded = true;
}

void ClKernel::unload()
{
    if ( kernel ) 
    {
      clReleaseKernel(kernel);
      kernel = 0;
    }
}

ClKernel::~ClKernel()
{
    unload();
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

  if ( !loaded ) 
  {
      platform.getKernelManager().loadKernel(this);
  }

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
  
  stats.registerCall();
  return *this;
}

cl_program ClKernel::getProgram()
{
    return program;
}

IClKernelCallStats& ClKernel::getStats()
{
    return stats;
}

