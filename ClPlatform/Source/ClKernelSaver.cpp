#include "ClKernelSaver.hpp"
#include "ClPlatform.hpp"
#include "ClKernel.hpp"
#include "logs.hpp"

namespace OPL
{

cl_int ClKernelSaver::getDeviceCount( shared_ptr<IClSingleImplementationKernel> kernel)
{
    cl_int error;
    cl_uint deviceCount = 0;

    error = clGetProgramInfo(kernel->getProgram(),
                             CL_PROGRAM_NUM_DEVICES,
                             sizeof(cl_uint),
                             &deviceCount, NULL);

    if ( error != CL_SUCCESS ) 
    {
        ERROR << "Error querying for number of devices, OpenCL error = " << error;
        throw OPEN_CL_ERROR;
    }

    return deviceCount;
}

void ClKernelSaver::getDevices( cl_device_id devices[], shared_ptr<IClSingleImplementationKernel> kernel )
{
    cl_int error;
    error = clGetProgramInfo(kernel->getProgram(),
                             CL_PROGRAM_DEVICES,
                             sizeof(devices),
                             devices,
                             NULL);
    if (error != CL_SUCCESS)
    {
        ERROR << "Error querying for devices, OpenCL error = " << error;
        throw OPEN_CL_ERROR;
    }
}

void ClKernelSaver::getBinarySizes( size_t binarySizes[], shared_ptr<IClSingleImplementationKernel> kernel )
{
    cl_int error;
    size_t sizeOfReturnedParam;
    error = clGetProgramInfo(kernel->getProgram(),
                             CL_PROGRAM_BINARY_SIZES,
                             sizeof(binarySizes),
                             binarySizes,
                             &sizeOfReturnedParam);

    if ( (error != CL_SUCCESS) || (sizeOfReturnedParam < sizeof(binarySizes)) )
    {
        ERROR << "Error querying for program binary sizes, OpenCL error = " << error;
        throw OPEN_CL_ERROR;
    }
}

void ClKernelSaver::getProgramBinaries( size_t deviceCount,
                                        size_t binarySizes[],
                                        unsigned char *programBinaries[],
                                        shared_ptr<IClSingleImplementationKernel> kernel)
{
    cl_int error;
    for (size_t i=0; i<deviceCount; i++) 
    {
        programBinaries[i] = new unsigned char[ binarySizes[i] ];
    }

    error = clGetProgramInfo(kernel->getProgram(),
                             CL_PROGRAM_BINARIES,
                             sizeof(programBinaries),
                             programBinaries,
                             NULL);

    if ( error != CL_SUCCESS ) 
    {
        ERROR << "Error querying for program binaries, OpenCL error = " << error;
        deleteProgramBinaries( deviceCount, programBinaries );
        throw OPEN_CL_ERROR;
    }
}

void ClKernelSaver::deleteProgramBinaries( size_t deviceCount, unsigned char *programBinaries[] )
{
    for (size_t i=0; i<deviceCount; i++) 
    {
        delete [] programBinaries[i];
    }
}

size_t ClKernelSaver::getDeviceIdx( size_t deviceCount, cl_device_id devices[] )
{
    ClPlatform& platform = ClPlatform::getPlatform();

    for (size_t i=0; i<deviceCount; i++) 
    {
        if ( devices[i] == platform.getDevice() ) 
        {
            return i;
        }
    }

    throw NO_DEVICE;
}

void ClKernelSaver::saveBinaryToFile( size_t binarySize, unsigned char *programBinary, FILE* file)
{
    size_t writtenElems = fwrite(&binarySize, sizeof(size_t), 1, file);
    if ( writtenElems < 1 ) 
    {
        ERROR << "Can't write to file ";
        throw FILE_WRITE_ERROR;
    }

    writtenElems = fwrite(programBinary, sizeof(unsigned char), binarySize, file);
    if ( writtenElems < binarySize ) 
    {
        ERROR << "Can't write to file ";
        throw FILE_WRITE_ERROR;
    }
    fclose(file);
}

void ClKernelSaver::saveKernel( shared_ptr<IClSingleImplementationKernel> kernel, std::string filename )
{
    DEBUG << "Saving kernel to file " << filename;

    FILE* file = openFile( filename );
    saveKernel( kernel, file );
    
    DEBUG << "Successfully saved kernel to file " << filename;
}

FILE* ClKernelSaver::openFile( std::string filename )
{
    FILE *file = fopen(filename.c_str(), "wb");
    if ( file == NULL ) 
    {
        ERROR << "Can't open file to write " << filename;
        throw FILE_WRITE_ERROR;
    }

    return file;
}

void ClKernelSaver::saveKernel( shared_ptr<IClSingleImplementationKernel> kernel, FILE* file )
{
    cl_uint deviceCount = getDeviceCount(kernel);
    cl_device_id devices[deviceCount];
    getDevices( devices, kernel );

    size_t binarySizes[deviceCount];
    getBinarySizes(binarySizes, kernel);

    unsigned char *programBinaries[deviceCount];
    getProgramBinaries( deviceCount, binarySizes, programBinaries, kernel );

    size_t deviceIdx = getDeviceIdx( deviceCount, devices );
    saveBinaryToFile( binarySizes[deviceIdx], programBinaries[deviceIdx], file );
    deleteProgramBinaries( deviceCount, programBinaries );
}

}

