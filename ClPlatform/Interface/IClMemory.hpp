#pragma once
#include <vector>
#include <CL/cl_gl.h>

class IClMemory
{
public:
  virtual bool isSetUpSuccessfully() = 0;
  virtual void copyIn (void*,uint,uint) = 0;
  virtual void copyOut(void*,uint,uint) = 0;
  virtual uint getSize() = 0;
  virtual std::vector<cl_mem> getMemories() = 0;
};

