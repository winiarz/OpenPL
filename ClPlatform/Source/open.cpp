#include "ClPlatform.hpp"
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <logs.hpp>

cl_program CreateProgram(cl_context context, cl_device_id device, const char* fileName)
{
  cl_int error;
  cl_program program;
  
  std::ifstream kernelFile(fileName, std::ios::in);
  if (!kernelFile.is_open())
  {
    ERROR << "Failed to open file for reading: " << fileName;
    return NULL;
  }
  
  std::ostringstream oss;
  oss << kernelFile.rdbuf();
  
  std::string srcStdStr = oss.str();
  const char *srcStr = srcStdStr.c_str();
  program = clCreateProgramWithSource(context,
                                      1,
                                      (const char**)&srcStr,
                                      NULL,
                                      &error);

  if ( (program == NULL) || ( error != CL_SUCCESS ) )
  {
    ERROR << "Failed to create CL program from source, error = " << error;
    return NULL;
  }
  
  error= clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
  if (error != CL_SUCCESS)
  {
    char buildLog[16384];
    clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
			  sizeof(buildLog), buildLog, NULL);
    
    ERROR << "Error in kernel: ";
    ERROR << buildLog;
    clReleaseProgram(program);
    return NULL;
  }
  
  return program;
}
