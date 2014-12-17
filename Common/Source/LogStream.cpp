#include "LogStream.hpp"
#include "logs.hpp"

LogStream::LogStream(int p_lineNb, std::string p_fileName, LogLevel p_logLevel) :
    lineNb(p_lineNb),
    fileName(p_fileName),
    logLevel(p_logLevel)
{}

std::ostream& operator<<(std::ostream& sstream, LogLevel logLevel)
{
    switch (logLevel) 
    {
    case LOG_LEVEL_ERROR:
        sstream << "ERR";
        break;
    case LOG_LEVEL_DEBUG:
        sstream << "DEB";
        break;
    }
    return sstream;
}

std::ostream& operator<<(std::ostream& sstream, OPL::OpenClError openClError)
{
    using namespace OPL;

    switch (openClError) 
    {
        case  OPENCL_SUCCESS:
            sstream << "OPENCL_SUCCESS";break;
        case OPENCL_DEVICE_NOT_FOUND:
            sstream << "OPENCL_DEVICE_NOT_FOUND"; break;
        case OPENCL_DEVICE_NOT_AVAILABLE:
            sstream << "OPENCL_DEVICE_NOT_AVAILABLE"; break;
        case OPENCL_COMPILER_NOT_AVAILABLE:
            sstream << "OPENCL_DEVICE_NOT_AVAILABLE"; break;
        case OPENCL_MEM_OBJECT_ALLOCATION_FAILURE:
            sstream << "OPENCL_MEM_OBJECT_ALLOCATION_FAILURE"; break;
        case OPENCL_OUT_OF_RESOURCES:
            sstream << "OPENCL_OUT_OF_RESOURCES"; break;
        case OPENCL_OUT_OF_HOST_MEMORY:
            sstream << "OPENCL_OUT_OF_HOST_MEMORY"; break;
        case OPENCL_PROFILING_INFO_NOT_AVAILABLE:
            sstream << "OPENCL_PROFILING_INFO_NOT_AVAILABLE"; break;
        case OPENCL_MEM_COPY_OVERLAP:
            sstream << "OPENCL_MEM_COPY_OVERLAP"; break;
        case OPENCL_IMAGE_FORMAT_MISMATCH:
            sstream << "OPENCL_IMAGE_FORMAT_MISMATCH"; break;
        case OPENCL_IMAGE_FORMAT_NOT_SUPPORTED:
            sstream << "OPENCL_IMAGE_FORMAT_NOT_SUPPORTED"; break;
        case OPENCL_BUILD_PROGRAM_FAILURE:
            sstream << "OPENCL_BUILD_PROGRAM_FAILURE"; break;
        case OPENCL_MAP_FAILURE:
            sstream << "OPENCL_MAP_FAILURE"; break;
        case OPENCL_CL_INVALID_VALUE:
            sstream << "OPENCL_CL_INVALID_VALUE"; break;
        case OPENCL_CL_INVALID_DEVICE_TYPE:
            sstream << "OPENCL_CL_INVALID_DEVICE_TYPE"; break;
        case OPENCL_CL_INVALID_PLATFORM:
            sstream << "OPENCL_CL_INVALID_PLATFORM"; break;
        case OPENCL_CL_INVALID_DEVICE:
            sstream << "OPENCL_CL_INVALID_DEVICE"; break;
        case OPENCL_CL_INVALID_CONTEXT:
            sstream << "OPENCL_CL_INVALID_CONTEXT"; break;
        case OPENCL_CL_INVALID_QUEUE_PROPERTIES:
            sstream << "OPENCL_CL_INVALID_QUEUE_PROPERTIES"; break;
        case OPENCL_CL_INVALID_COMMAND_QUEUE:
            sstream << "OPENCL_CL_INVALID_COMMAND_QUEUE"; break;
        case OPENCL_CL_INVALID_HOST_PTR:
            sstream << "OPENCL_CL_INVALID_HOST_PTR"; break;
        case OPENCL_CL_INVALID_MEM_OBJECT:
            sstream << "OPENCL_CL_INVALID_MEM_OBJECT"; break;
        case OPENCL_CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
            sstream << "OPENCL_CL_INVALID_IMAGE_FORMAT_DESCRIPTOR"; break;
        case OPENCL_CL_INVALID_IMAGE_SIZE:
            sstream << "OPENCL_CL_INVALID_IMAGE_SIZE"; break;
        case OPENCL_CL_INVALID_SAMPLER:
            sstream << "OPENCL_CL_INVALID_SAMPLER"; break;
        case OPENCL_CL_INVALID_BINARY:
            sstream << "OPENCL_CL_INVALID_BINARY"; break;
        case OPENCL_CL_INVALID_BUILD_OPTIONS:
            sstream << "OPENCL_CL_INVALID_BUILD_OPTIONS"; break;
        case OPENCL_CL_INVALID_PROGRAM:
            sstream << "OPENCL_CL_INVALID_PROGRAM"; break;
        case OPENCL_CL_INVALID_PROGRAM_EXECUTABLE:
            sstream << "OPENCL_CL_INVALID_PROGRAM_EXECUTABLE"; break;
        case OPENCL_CL_INVALID_KERNEL_NAME:
            sstream << "OPENCL_CL_INVALID_KERNEL_NAME"; break;
        case OPENCL_CL_INVALID_KERNEL_DEFINITION:
            sstream << "OPENCL_CL_INVALID_KERNEL_DEFINITION"; break;
        case OPENCL_CL_INVALID_KERNEL:
            sstream << "OPENCL_CL_INVALID_KERNEL"; break;
        case OPENCL_CL_INVALID_ARG_INDEX:
            sstream << "OPENCL_CL_INVALID_ARG_INDEX"; break;
        case OPENCL_CL_INVALID_ARG_VALUE:
            sstream << "OPENCL_CL_INVALID_ARG_VALUE"; break;
        case OPENCL_CL_INVALID_ARG_SIZE:
            sstream << "OPENCL_CL_INVALID_ARG_SIZE"; break;
        case OPENCL_CL_INVALID_KERNEL_ARGS:
            sstream << "OPENCL_CL_INVALID_KERNEL_ARGS"; break;
        case OPENCL_CL_INVALID_WORK_DIMENSION:
            sstream << "OPENCL_CL_INVALID_WORK_DIMENSION"; break;
        case OPENCL_CL_INVALID_WORK_GROUP_SIZE:
            sstream << "OPENCL_CL_INVALID_WORK_GROUP_SIZE"; break;
        case OPENCL_CL_INVALID_WORK_ITEM_SIZE:
            sstream << "OPENCL_CL_INVALID_WORK_ITEM_SIZE"; break;
        case OPENCL_CL_INVALID_GLOBAL_OFFSET:
            sstream << "OPENCL_CL_INVALID_GLOBAL_OFFSET"; break;
        case OPENCL_CL_INVALID_EVENT_WAIT_LIST:
            sstream << "OPENCL_CL_INVALID_EVENT_WAIT_LIST"; break;
        case OPENCL_CL_INVALID_EVENT:
            sstream << "OPENCL_CL_INVALID_EVENT"; break;
        case OPENCL_CL_INVALID_OPERATION:
            sstream << "OPENCL_CL_INVALID_OPERATION"; break;
        case OPENCL_CL_INVALID_GL_OBJECT:
            sstream << "OPENCL_CL_INVALID_GL_OBJECT"; break;
        case OPENCL_CL_INVALID_BUFFER_SIZE:
            sstream << "OPENCL_CL_INVALID_BUFFER_SIZE"; break;
        case OPENCL_CL_INVALID_MIP_LEVEL:
            sstream << "OPENCL_CL_INVALID_MIP_LEVEL"; break;
        case OPENCL_CL_INVALID_GLOBAL_WORK_SIZE:
            sstream << "OPENCL_CL_INVALID_GLOBAL_WORK_SIZE"; break;
        default:
            sstream << "UNKNOWN OPENCL ERROR code='" << int(openClError) << "'"; break;
    }

    return sstream;
}

LogStream::~LogStream()
{
    static std::ofstream debugFile(debugFileName,std::ofstream::out);

    debugFile << fileName << ":" << lineNb << " " << this->str() << std::endl;
}

