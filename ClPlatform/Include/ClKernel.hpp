
#ifndef __CL_KERNEL__
#define __CL_KERNEL__

#include "IClKernel.hpp"
#include "ClClasses.hpp"
#include "ClPlatform.hpp"
#include "ClMemory.hpp"

class ClKernel : public IClKernel {
public:
  ClKernel( const char[], const char[]);
  bool isLoaded();
  bool isSetUpSuccessfully();
  bool operator!();
  IClKernel& operator[](uint);
  IClKernel& operator()(uint, ... );
  ~ClKernel();
private:
  const ClPlatform& platform;
  cl_program program;
  cl_kernel kernel;

  size_t globalSize;
  size_t localSize;

  bool setUpSuccessfully;
};

#endif

