#include "ClPlatform.hpp"
#include "logs.hpp"
#include <iostream>
using namespace std;

ClPlatform& ClPlatform::getPlatform()
{
  static ClPlatform onlyPlatform;
  return onlyPlatform;
}

ClPlatform::ClPlatform()
{
  cl_uint platformNb;
  cl_int error = clGetPlatformIDs( 1, &platform, &platformNb );
  if( (error != CL_SUCCESS) || (platformNb < 1) )
  {
      ERROR << "clGetPlatformIDs OpenCL error = " << OpenClError(error);
      setUpSuccessfully=false;
      return;
  }

  cl_uint deviceNb;
  error = clGetDeviceIDs( platform, CL_DEVICE_TYPE_GPU, 1, &device, &deviceNb );
  if( (error != CL_SUCCESS) || (deviceNb < 1) || (!device) )
  {
      ERROR << "clGetDeviceIDs OpenCL error = " << OpenClError(error);
      setUpSuccessfully=false;
      return;
  }

  context = clCreateContext(0, 1, &device, NULL, NULL, &error);
  if( (error != CL_SUCCESS) || (!context) )
  {
      ERROR << "clCreateContext OpenCL error = " << OpenClError(error);
      setUpSuccessfully=false;
      return;
  }

  queue = clCreateCommandQueue(context, device, 0, &error);
  if( (error != CL_SUCCESS) || (!queue) )
  {
      ERROR << "clCreateCommandQueue OpenCL error = " << OpenClError(error);
      setUpSuccessfully=false;
      return;
  }
  
  error = clGetDeviceInfo(device,CL_DEVICE_MAX_WORK_GROUP_SIZE,sizeof(size_t),&max_work_group_size,NULL); // TODO create class DeviceInfo and move it there
  if(error != CL_SUCCESS)
  {
      ERROR << "clGetDeviceInfo OpenCL error = " << OpenClError(error);
      setUpSuccessfully=false;
      return;
  }

  setUpSuccessfully = true;
}

bool ClPlatform::isSetUpSuccessfully()
{
	return setUpSuccessfully;
}

void ClPlatform::execute() const
{
  cl_int error = clFinish(queue);
  if ( error != CL_SUCCESS )
  {
      ERROR << "clFinish error = " << OpenClError(error);
  }
}

cl_context ClPlatform::getContext() const
{
  return context;
}

cl_device_id ClPlatform::getDevice() const
{
  return device;
}

ClPlatform::~ClPlatform()
{
  clReleaseCommandQueue(queue);
  clReleaseContext(context);
}

IClKernelManager& ClPlatform::getKernelManager()
{
    return kernelManager;
}
