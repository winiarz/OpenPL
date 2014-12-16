#pragma once

#include <CL/cl.h>
#include "ClClasses.hpp"
#include "ClKernelManager.hpp"
#include "ClError.hpp"

class ClKernelManager;

namespace OPL
{

class ClPlatform {
friend class ClMemory;
public:
  static ClPlatform& getPlatform();
  bool isSetUpSuccessfully();
  void execute() const;
  cl_context getContext() const;
  cl_device_id getDevice() const;
  IClKernelManager& getKernelManager();
  cl_command_queue getCommandQueue() const
  {
      return queue;
  }
  cl_context getOpenClContext() const
  {
      return context;
  }

  ~ClPlatform();
  cl_uint max_work_group_size;
private:
  ClPlatform();
  cl_platform_id platform;
  cl_device_id device;
  cl_context context;
  cl_command_queue queue;

  bool setUpSuccessfully;
  ClKernelManager kernelManager;
};

}

