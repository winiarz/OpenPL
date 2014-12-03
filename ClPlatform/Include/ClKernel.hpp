#pragma once

#include "IClSingleImplementationKernel.hpp"
#include "ClClasses.hpp"
#include "ClPlatform.hpp"
#include "ClMemory.hpp"
#include "ClKernelCallStats.hpp"
#include "stl.hpp"

class ClKernel : public IClSingleImplementationKernel {
public:
  ClKernel( const char[], const char[]);
  ClKernel( cl_program, std::string p_kernelName = "kernelName" );
  bool isLoaded();
  bool isSetUpSuccessfully();
  bool operator!();
  IClKernel& operator[](uint);
  IClKernel& operator()(uint, ... );
  virtual IClKernel& operator()(std::vector<ClMemory*>);
  virtual IClKernel& operator()(std::vector<shared_ptr<ClMemory>>);
  virtual cl_program getProgram();
  virtual void load();
  virtual void unload();
  IClKernelCallStats& getStats();
  std::string getKernelName();
  ~ClKernel();
private:
  ClPlatform& platform;
  cl_program program;
  cl_kernel kernel;

  size_t globalSize;
  size_t localSize;

  bool loaded;
  std::string kernelName;
  ClKernelCallStats stats;
  void setKernelArg(uint, ClMemory*);
  void checkThreadCount();
  void executeKernel();
};

