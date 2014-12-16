#include "OpenClCompiler.hpp"
#include "ClPlatform.hpp"
#include "logs.hpp"

OpenClCompiler::OpenClCompiler()
{
}

cl_program OpenClCompiler::compile(std::string& sourceCode) const
{
    OPL::ClPlatform& platform = OPL::ClPlatform::getPlatform();

    cl_int error;

    const char* sourceCString = sourceCode.c_str();

    cl_program program = clCreateProgramWithSource(platform.getContext(),
                                                   1,
                                                   &sourceCString,
                                                   NULL,
                                                   &error);

    if ( (program == NULL) || ( error != CL_SUCCESS ) )
    {
        ERROR << "Failed to create CL program from source, error = " << error;
        throw OPEN_CL_ERROR;
    }

    error = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (error != CL_SUCCESS)
    {
        char buildLog[MAX_BUILD_LOG_SIZE];
        clGetProgramBuildInfo(program,
                              platform.getDevice(),
                              CL_PROGRAM_BUILD_LOG,
                              sizeof(buildLog),
                              buildLog,
                              NULL);

        ERROR << "Error in kernel: ";
        ERROR << buildLog;
        clReleaseProgram(program);
        return NULL;
    }

    return program;
}
