#include "ClPlatform.hpp"
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <logs.hpp>

cl_program CreateProgramFromBinary(cl_context context, cl_device_id device, const char* fileName)
{
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        ERROR << "can't open file: " << fileName;
        return NULL;
    }

    size_t binarySize;
    fseek(fp, 0, SEEK_END);
    binarySize = ftell(fp);
    rewind(fp);

    unsigned char *programBinary = new unsigned char[binarySize];
    fread(programBinary, 1, binarySize, fp);
    fclose(fp);

    cl_int error = 0;
    cl_program program;
    cl_int binaryStatus;

    program = clCreateProgramWithBinary(context,
                                        1,
                                        &device,
                                        &binarySize,
                                        (const unsigned char**)&programBinary,
                                        &binaryStatus,
                                        &error);
    delete [] programBinary;
    if (error != CL_SUCCESS)
    {
        ERROR << "Error loading program binary " << fileName << " error = " << error;
        return NULL;
    }

    if (binaryStatus != CL_SUCCESS)
    {
        ERROR << "Invalid binary for device " << fileName;
        return NULL;
    }

    error= clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (error != CL_SUCCESS)
    {
        char buildLog[16384];
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
                              sizeof(buildLog), buildLog, NULL);

        ERROR << "Error in program: " << fileName;
        ERROR << buildLog;
        clReleaseProgram(program);
        return NULL;
    }

    return program;
}

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
