#include <CL/cl.h>
#include "ClKernelFromBinaryLoader.hpp"
#include "ClPlatform.hpp"
#include "ClError.hpp"
#include "logs.hpp"
#include "ClKernel.hpp"

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

size_t ClKernelFromBinaryLoader::readBinarySize( FILE* file )
{
    size_t binarySize;
    size_t readSize = fread( &binarySize, sizeof(binarySize), 1, file);

    if ( readSize < 1 ) 
    {
        ERROR << "Kernel file is too short";
        throw INCORRECT_KERNEL_FILE;
    }

    return binarySize;
}

unsigned char* ClKernelFromBinaryLoader::readBinary( FILE* file, size_t binarySize )
{
    unsigned char *binary = new unsigned char[binarySize];
    size_t readSize = fread(binary, 1, binarySize, file);

    if ( readSize < binarySize ) 
    {
        delete [] binary;
        ERROR << "Kernel file is too short, expected read size = " << binarySize << " actual = " << readSize;
        throw INCORRECT_KERNEL_FILE;
    }

    return binary;
}

std::shared_ptr<ClKernel> ClKernelFromBinaryLoader::loadKernel(std::string filename)
{
    FILE* file = openFile( filename );
		return loadKernel( file );
}

std::shared_ptr<ClKernel> ClKernelFromBinaryLoader::loadKernel( FILE* file )
{
    size_t binarySize = readBinarySize( file );
    unsigned char * binary = readBinary( file, binarySize );

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
        ERROR << "Error program binary is incorrect!, error = " << error;
        throw INCORRECT_KERNEL_FILE;
    }

    error = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

    if (error != CL_SUCCESS)
    {
        char buildLog[MAX_BUILD_LOG_SIZE];
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG,
                              sizeof(buildLog), buildLog, NULL);

        ERROR << "Error in program:";
        ERROR << buildLog;
        clReleaseProgram(program);
        throw INCORRECT_KERNEL_FILE;
    }

    return std::make_shared<ClKernel>(program);
}

