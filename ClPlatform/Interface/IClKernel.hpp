#ifndef __I_CL_KERNEL__
#define __I_CL_KERNEL__

#include <CL/cl.h>

typedef unsigned int uint;

class IClKernelCallStats;

class IClKernel {
public:
  virtual bool isSetUpSuccessfully()=0;
  virtual bool operator!()=0;
  virtual IClKernel& operator[](uint n)=0;
  virtual IClKernel& operator()(uint, ... )=0;
  //virtual cl_program getProgram()=0;
  //virtual IClKernelCallStats& getStats()=0;
  
  virtual ~IClKernel(){}
};

#endif
