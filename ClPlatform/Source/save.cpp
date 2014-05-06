#include "ClPlatform.hpp"
#include <fstream>
#include <sstream>
#include "logs.hpp"

bool SaveProgramBinary(cl_program program, cl_device_id device, const char* fileName)
{
    cl_uint numDevices = 0;
    cl_int error;

    error = clGetProgramInfo(program, CL_PROGRAM_NUM_DEVICES, sizeof(cl_uint),
                              &numDevices, NULL);
    if (error != CL_SUCCESS)
    {
        ERROR << "Error querying for number of devices, OpenCL error = " << error;
        return false;
    }

    cl_device_id *devices = new cl_device_id[numDevices];
    error = clGetProgramInfo(program, CL_PROGRAM_DEVICES,
                              sizeof(cl_device_id) * numDevices,
                              devices, NULL);
    if (error != CL_SUCCESS)
    {
        ERROR << "Error querying for devices, OpenCL error = " << error;
        delete [] devices;
        return false;
    }

    size_t *programBinarySizes = new size_t [numDevices];
    error = clGetProgramInfo(program, CL_PROGRAM_BINARY_SIZES,
                              sizeof(size_t) * numDevices,
                              programBinarySizes, NULL);
    if (error != CL_SUCCESS)
    {
        ERROR << "Error querying for program binary sizes, OpenCL error = " << error;
        delete [] devices;
        delete [] programBinarySizes;
        return false;
    }

    unsigned char **programBinaries = new unsigned char*[numDevices];
    for (cl_uint i = 0; i < numDevices; i++)
    {
        programBinaries[i] = new unsigned char[programBinarySizes[i]];
    }

    error = clGetProgramInfo(program, CL_PROGRAM_BINARIES, sizeof(unsigned char*) * numDevices,
                              programBinaries, NULL);
    if (error != CL_SUCCESS)
    {
        ERROR << "Error querying for program binaries, OpenCL error = " << error;

        delete [] devices;
        delete [] programBinarySizes;
        for (cl_uint i = 0; i < numDevices; i++)
        {
            delete [] programBinaries[i];
        }
        delete [] programBinaries;
        return false;
    }

    for (cl_uint i = 0; i < numDevices; i++)
    {
        if (devices[i] == device)
        {
            FILE *fp = fopen(fileName, "wb");
            fwrite(programBinaries[i], 1, programBinarySizes[i], fp);
            fclose(fp);
            break;
        }
    }

    delete [] devices;
    delete [] programBinarySizes;
    for (cl_uint i = 0; i < numDevices; i++)
    {
        delete [] programBinaries[i];
    }
    delete [] programBinaries;
    return true;
}
