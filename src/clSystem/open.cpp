#include "clSystem/system.h"
#include <iostream>
#include <fstream>
#include <sstream>
 
cl_program CreateProgramFromBinary(cl_context context, cl_device_id device, const char* fileName)
{
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        return NULL;
    }

    // Determine the size of the binary
    size_t binarySize;
    fseek(fp, 0, SEEK_END);
    binarySize = ftell(fp);
    rewind(fp);

    unsigned char *programBinary = new unsigned char[binarySize];
    fread(programBinary, 1, binarySize, fp);
    fclose(fp);

    cl_int errNum = 0;
    cl_program program;
    cl_int binaryStatus;

    program = clCreateProgramWithBinary(context,
                                        1,
                                        &device,
                                        &binarySize,
                                        (const unsigned char**)&programBinary,
                                        &binaryStatus,
                                        &errNum);
    delete [] programBinary;
    if (errNum != CL_SUCCESS)
    {
        std::cerr << "Error loading program binary." << std::endl;
        return NULL;
    }

    if (binaryStatus != CL_SUCCESS)
    {
        std::cerr << "Invalid binary for device" << std::endl;
        return NULL;
    }

    errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (errNum != CL_SUCCESS)
    {
        // Determine the reason for the error
        char buildLog[16384];
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
                              sizeof(buildLog), buildLog, NULL);

        std::cerr << "Error in program: " << std::endl;
        std::cerr << buildLog << std::endl;
        clReleaseProgram(program);
        return NULL;
    }

    return program;
}

cl_program CreateProgram(cl_context context, cl_device_id device, const char* fileName)
{
  cl_int errNum;
  cl_program program;
  
  std::ifstream kernelFile(fileName, std::ios::in);
  if (!kernelFile.is_open())
  {
    std::cerr << "Failed to open file for reading: " << fileName << std::endl;
    return NULL;
  }
  
  std::ostringstream oss;
  oss << kernelFile.rdbuf();
  
  std::string srcStdStr = oss.str();
  const char *srcStr = srcStdStr.c_str();
  program = clCreateProgramWithSource(context, 1,
				      (const char**)&srcStr,
				      NULL, NULL);
  if (program == NULL)
  {
    std::cerr << "Failed to create CL program from source." << std::endl;
    return NULL;
  }
  
  errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
  if (errNum != CL_SUCCESS)
  {
    // Determine the reason for the error
    char buildLog[16384];
    clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
			  sizeof(buildLog), buildLog, NULL);
    
    std::cerr << "Error in kernel: " << std::endl;
    std::cerr << buildLog;
    clReleaseProgram(program);
    return NULL;
  }
  
  return program;
}
