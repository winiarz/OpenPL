#include <CL/cl.h>
#include "ClKernelFromBinaryLoader.hpp"
#include "ClPlatform.hpp"
#include "ClError.hpp"
#include "logs.hpp"

const int MAX_BUILD_LOG_SIZE = 16384;

FILE* ClKernelFromBinaryLoader::openFile(std::string& filename)
{
    FILE* file = fopen(filename.c_str(), "rb");
    if (file == NULL)
    {
        ERROR << "can't open file: " << filename;
        throw FILE_READ_ERROR;
    }

    return file;
}

size_t ClKernelFromBinaryLoader::readBinarySize( FILE* file, std::string& filename )
{
    size_t binarySize;
    size_t readSize = fread( &binarySize, sizeof(binarySize), 1, file);

    if ( readSize < 1 ) 
    {
        ERROR << "Kernel file " << filename << " is too short";
        throw CL_INCORRECT_KERNEL_FILE;
    }

    return binarySize;
}

unsigned char* ClKernelFromBinaryLoader::readBinary( FILE* file, size_t binarySize, std::string& filename )
{
    unsigned char *binary = new unsigned char[binarySize];
    size_t readSize = fread(binary, 1, binarySize, file);

    if ( readSize < binarySize ) 
    {
        delete [] binary;
        ERROR << "Kernel file " << filename << " is too short, expected read size = " << binarySize << " actual = " << readSize;
        throw CL_INCORRECT_KERNEL_FILE;
    }

    return binary;
}

boost::shared_ptr<IClKernel> ClKernelFromBinaryLoader::loadKernel(std::string filename)
{
    FILE* file = openFile( filename );

    size_t binarySize = readBinarySize( file, filename );
    unsigned char * binary = readBinary( file, binarySize, filename );

    ClPlatform& platform = ClPlatform::getPlatform();

    cl_context context = platform.getContext();
    cl_device_id device = platform.getDevice();

    cl_int error;
    cl_program program;
    cl_int binaryStatus;

    program = clCreateProgramWithBinary(context,
                                        1,
                                        &device,
                                        &binarySize,
                                        (const unsigned char**)&binary,
                                        &binaryStatus,
                                        &error);

    delete [] binary;

    if ( (error != CL_SUCCESS) || (binaryStatus != CL_SUCCESS) ) 
    {
        ERROR << "Error program binary " << filename << " is incorrect!, error = " << error;
        throw CL_INCORRECT_KERNEL_FILE;
    }

    error = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (error != CL_SUCCESS)
    {
        char buildLog[MAX_BUILD_LOG_SIZE];
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
                              sizeof(buildLog), buildLog, NULL);

        ERROR << "Error in program: " << filename;
        ERROR << buildLog;
        clReleaseProgram(program);
        throw CL_INCORRECT_KERNEL_FILE;
    }

    return boost::shared_ptr<IClKernel>();
}

