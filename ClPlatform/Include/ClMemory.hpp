#pragma once

#include "IClMemory.hpp"
#include <GL/glew.h>
#include <CL/cl_gl.h>

namespace OPL
{
class ClPlatform;

enum ClMemoryCreation {
  CL_MEMORY_ALLOC,
  CL_MEMORY_USE_GL_BUFFER
};


uint calculateSize(uint, ClMemoryCreation, size_t);

class ClMemory : public IClMemory
{
public:
  ClMemory(uint, ClMemoryCreation = CL_MEMORY_ALLOC );
  bool operator!();
  bool isSetUpSuccessfully();
  void copyIn (void*,uint,uint);
  void copyOut(void*,uint,uint);
  uint getSize();
  std::vector<cl_mem> getMemories();
private:
  const ClPlatform& platform;
  const uint size;
  cl_mem memory;
};

}

