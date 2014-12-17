#pragma once

#include "IClSingleImplementationKernel.hpp"
#include "ClClasses.hpp"
#include "ClPlatform.hpp"
#include "IClMemory.hpp"
#include "ClKernelCallStats.hpp"
#include "stl.hpp"

namespace OPL
{

class ClKernel : public IClSingleImplementationKernel {
public:
  ClKernel( const char[], const char[]);
  ClKernel( cl_program, std::string p_kernelName = "kernelName" );
  bool isLoaded();
  bool isSetUpSuccessfully();
  bool operator!();
  IClKernel& operator[](uint);
  IClKernel& operator()(uint, ... );
  virtual IClKernel& operator()(std::vector<OPL::IClMemory*>);
  virtual IClKernel& operator()(std::vector<shared_ptr<OPL::IClMemory>>);
  virtual cl_program getProgram();
  virtual void load();
  virtual void unload();
  OPL::IClKernelCallStats& getStats();
  std::string getKernelName();
  ~ClKernel();
private:
  OPL::ClPlatform& platform;
  cl_program program;
  cl_kernel kernel;

  size_t globalSize;
  size_t localSize;

  bool loaded;
  std::string kernelName;
  OPL::ClKernelCallStats stats;
  void setKernelArg(uint&, OPL::IClMemory*);
  void checkThreadCount();
  void executeKernel();
};

}

