#include <stdarg.h>
#include "ClKernel.hpp"
#include "IClMemory.hpp"
#include "ClKernelFromBinaryLoader.hpp"
#include "Clock.hpp"
#include "logs.hpp"

ClKernel::ClKernel( const char fileName[], const char p_kernelName[] ) :
    platform(OPL::ClPlatform::getPlatform()),
    kernel(0),
    loaded(false),
    kernelName(p_kernelName),
    stats(make_shared<Clock>(), 0.95f)
{
    try
    {
        shared_ptr<ClKernel> tempKernel = ClKernelFromBinaryLoader().loadKernel(fileName);
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
        return;
    }

    localSize = 0;
    globalSize = 0;

}

ClKernel::ClKernel( cl_program p_program, std::string p_kernelName) :
    platform(OPL::ClPlatform::getPlatform()),
    program(p_program),
    kernel(0),
    globalSize(0),
    localSize(0),
    loaded(false),
    kernelName(p_kernelName),
    stats(make_shared<Clock>(), 0.95f)
{
}

void ClKernel::load()
{
    DEBUG << "trying to load kernel " << kernelName;
    cl_int error;
    kernel = clCreateKernel( program, kernelName.c_str(), &error );
    if( (!kernel) || (error != CL_SUCCESS) )
    {
        ERROR << "error in creating kernel OpenCL error = " << OpenClError(error);
        loaded = false;
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
      loaded = false;
    }
}

ClKernel::~ClKernel()
{
    unload();
}

bool ClKernel::isLoaded()
{
  return loaded;
}

bool ClKernel::isSetUpSuccessfully()
{
    return program != 0;
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
    va_list li;
  
    if ( !loaded ) 
    {
        platform.getKernelManager().loadKernel(this);
    }

    va_start(li,argumentNb);

    uint argIdx=0;
    for(uint i=0; i < argumentNb; i++)
    {
        OPL::IClMemory* memory = va_arg(li, OPL::IClMemory*);
        setKernelArg(argIdx, memory);
    }
    va_end(li);

    executeKernel();
    return *this;
}

cl_program ClKernel::getProgram()
{
    return program;
}

OPL::IClKernelCallStats& ClKernel::getStats()
{
    return stats;
}

void ClKernel::setKernelArg(uint& idx, OPL::IClMemory* arg)
{
    auto memories = arg->getMemories();
    for (cl_mem memory : memories) 
    {
        cl_int error = clSetKernelArg( kernel, idx, sizeof(memory), &memory );
        if( error != CL_SUCCESS )
        {
            ERROR << "error in setting kernel arg argNb = " << idx << "OpenCL error = " << OpenClError(error);
            throw KERNEL_SET_ARG_ERROR;
        }
        ++idx;
    }
}

void ClKernel::checkThreadCount()
{
    if( (globalSize <= 0) || (localSize <= 0) )
    {
        ERROR << "running kernel without setting threads nb first";
        throw KERNEL_SIZE_NOT_SET; 
    }
}

void ClKernel::executeKernel()
{
    checkThreadCount();
    cl_int error = clEnqueueNDRangeKernel( platform.getCommandQueue(), kernel, 1, NULL,  &globalSize, &localSize, 0, NULL, NULL);
    if( error != CL_SUCCESS )
    {
        ERROR << "error in kernel execution OpenCL error = " << OpenClError(error);
        throw KERNEL_EXEC_ERROR;
    }
    platform.execute();
  
    stats.registerCall();
    DEBUG << "Kernel " << kernelName << "successfully executed!";
}

IClKernel& ClKernel::operator()(std::vector<OPL::IClMemory*> args)
{
    if ( !loaded ) 
    {
        platform.getKernelManager().loadKernel(this);
    }

    uint argIdx=0;
    for (auto arg : args)
    {
        setKernelArg(argIdx, arg);
    }

    executeKernel();
    return *this;
}

IClKernel& ClKernel::operator()(std::vector<shared_ptr<OPL::IClMemory>> args)
{
    if ( !loaded ) 
    {
        platform.getKernelManager().loadKernel(this);
    }

    uint argIdx=0;
    for (auto arg : args)
    {
        setKernelArg(argIdx, arg.get());
    }

    executeKernel();
    return *this;
}

std::string ClKernel::getKernelName()
{
    return kernelName;
}

