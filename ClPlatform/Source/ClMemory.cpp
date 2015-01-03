#include "ClMemory.hpp"
#include "ClPlatform.hpp"
#include "logs.hpp"

namespace OPL
{

uint getSizeOfBuffer(uint p_size, ClMemoryCreation creationType)
{
  switch( creationType )
  {
    case CL_MEMORY_ALLOC:
        return p_size;
    case CL_MEMORY_USE_GL_BUFFER:
    {
        GLuint glBuffer = p_size;
        int bufferSize = 0;
        glBindBuffer(GL_ARRAY_BUFFER, glBuffer);
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
        return bufferSize;
    }
    default:
      return 0;
  }
}

ClMemory::ClMemory(uint p_size, ClMemoryCreation creationType) :
	      platform(ClPlatform::getPlatform()),
	      size(getSizeOfBuffer(p_size, creationType))
{
  cl_int error;
  switch( creationType )
  {
    case CL_MEMORY_ALLOC:
    {
      memory = clCreateBuffer(platform.getOpenClContext(), CL_MEM_READ_WRITE, size, NULL, &error);
      break;
    }
    case CL_MEMORY_USE_GL_BUFFER:
    {
      GLuint glBuffer = p_size;
      DEBUG << "creating ClMemory from OpenGL buffer " << glBuffer;
      memory = clCreateFromGLBuffer(platform.getOpenClContext(), CL_MEM_READ_WRITE, glBuffer, NULL);
      break;
    }
  }
  if( (!memory) || (error != CL_SUCCESS) )
  {
      ERROR << "error in memory allocation OpenCL error = " << OpenClError(error);
      return;
  }
    
}

bool ClMemory::isSetUpSuccessfully()
{
    return memory != 0;
}

std::vector<cl_mem> ClMemory::getMemories()
{
    return std::vector<cl_mem> {memory};
}

bool ClMemory::operator!()
{
   return !isSetUpSuccessfully();
}

void ClMemory::copyIn(void* data, uint start, uint p_size)
{
  cl_int error;
  error = clEnqueueWriteBuffer( platform.getCommandQueue(), memory, CL_TRUE, start, p_size, data, 0, NULL, NULL);
  if(error != CL_SUCCESS)
  {
      ERROR << "error in copying memory to device, OpenCL error = " << OpenClError(error);
      throw INTER_DEVICE_COPY_ERROR;
  }
}

void ClMemory::copyOut(void* data, uint start, uint p_size)
{
  cl_int error;
  error = clEnqueueReadBuffer( platform.getCommandQueue(), memory, CL_TRUE, start, p_size, data, 0, NULL, NULL);
  if(error != CL_SUCCESS)
  {
      ERROR << "error in copying memory to device, OpenCL error = " << OpenClError(error);
      throw INTER_DEVICE_COPY_ERROR;
  }
}

uint ClMemory::getSize()
{
  return size;
}

uint calculateSize(uint n, ClMemoryCreation clMemoryCreation, size_t sizeOfType)
{
  switch( clMemoryCreation )
  {
    case CL_MEMORY_ALLOC:
      return sizeOfType * n;
    case CL_MEMORY_USE_GL_BUFFER:
      return n;
    default:
      return 0;
  }
}

}

