#include "ClKernelFromSourceLoader.hpp"
#include "ClPlatform.hpp"
#include "ClKernel.hpp"
#include "ClError.hpp"
#include "logs.hpp"
#include "stl.hpp"

boost::shared_ptr<ClKernel> ClKernelFromSourceLoader::loadKernel(std::string filename)
{
    boost::shared_ptr<std::string> source = readFile(filename);

    cl_program program = compileSource( source );
    return boost::make_shared<ClKernel>(program);
}

cl_program ClKernelFromSourceLoader::compileSource(boost::shared_ptr<std::string> source)
{
    ClPlatform& platform = ClPlatform::getPlatform();

    cl_int error;

    const char* sourceCString = source->c_str();

    cl_program program = clCreateProgramWithSource(platform.getContext(),
                                                   1,
                                                   (const char**)&sourceCString,
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

boost::shared_ptr<std::string> ClKernelFromSourceLoader::readFile(std::string& filename)
{
    std::ifstream file(filename);
    if ( !file.is_open() ) 
    {
        ERROR << "error while reading file " << filename;
        throw FILE_READ_ERROR;
    }

    boost::shared_ptr<std::string> text = boost::make_shared<std::string>();

    file.seekg(0, std::ios::end);   
    text->reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    text->assign( std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>() );

    return text;
}
