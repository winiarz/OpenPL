
#ifndef __CL_KERNEL__
#define __CL_KERNEL__

#include "IClKernel.hpp"
#include "ClClasses.hpp"
#include "ClPlatform.hpp"
#include "ClMemory.hpp"
#include "stl.hpp"

class ClKernel : public IClKernel {
public:
  ClKernel( const char[], const char[]);
  ClKernel( cl_program );
  bool isLoaded();
  bool isSetUpSuccessfully();
  bool operator!();
  IClKernel& operator[](uint);
  IClKernel& operator()(uint, ... );
  virtual cl_program getProgram();
  ~ClKernel();
private:
  const ClPlatform& platform;
  cl_program program;
  cl_kernel kernel;

  size_t globalSize;
  size_t localSize;

  bool setUpSuccessfully;
  bool loaded;
  std::string kernelName;

  void createKernel();
};

#endif

