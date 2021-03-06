#pragma once

namespace OPL
{

enum ClError {
    UNDEFINED,
    OPEN_CL_ERROR,
    NO_PLATFORM,
    NO_DEVICE,
    KERNEL_SIZE_NOT_SET,
    KERNEL_SET_ARG_ERROR,
    KERNEL_EXEC_ERROR,
    INTER_DEVICE_COPY_ERROR,
    OUT_OF_RESOURCES,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR,
    INCORRECT_KERNEL_FILE,
    INCORRECT_DATA_GENERATOR_FILE,
    NO_KERNEL_IN_COMPARATOR
};

enum OpenClError {
 OPENCL_SUCCESS = 0,
 OPENCL_DEVICE_NOT_FOUND = -1,
 OPENCL_DEVICE_NOT_AVAILABLE = -2,
 OPENCL_COMPILER_NOT_AVAILABLE = -3,
 OPENCL_MEM_OBJECT_ALLOCATION_FAILURE = -4,
 OPENCL_OUT_OF_RESOURCES = -5,
 OPENCL_OUT_OF_HOST_MEMORY = -6,
 OPENCL_PROFILING_INFO_NOT_AVAILABLE = -7,
 OPENCL_MEM_COPY_OVERLAP = -8,
 OPENCL_IMAGE_FORMAT_MISMATCH = -9,
 OPENCL_IMAGE_FORMAT_NOT_SUPPORTED = -10,
 OPENCL_BUILD_PROGRAM_FAILURE = -11,
 OPENCL_MAP_FAILURE = -12,
 OPENCL_CL_INVALID_VALUE = -30,
 OPENCL_CL_INVALID_DEVICE_TYPE = -31,
 OPENCL_CL_INVALID_PLATFORM = -32,
 OPENCL_CL_INVALID_DEVICE = -33,
 OPENCL_CL_INVALID_CONTEXT = -34,
 OPENCL_CL_INVALID_QUEUE_PROPERTIES = -35,
 OPENCL_CL_INVALID_COMMAND_QUEUE = -36,
 OPENCL_CL_INVALID_HOST_PTR = -37,
 OPENCL_CL_INVALID_MEM_OBJECT = -38,
 OPENCL_CL_INVALID_IMAGE_FORMAT_DESCRIPTOR = -39,
 OPENCL_CL_INVALID_IMAGE_SIZE = -40,
 OPENCL_CL_INVALID_SAMPLER = -41,
 OPENCL_CL_INVALID_BINARY = -42,
 OPENCL_CL_INVALID_BUILD_OPTIONS = -43,
 OPENCL_CL_INVALID_PROGRAM = -44,
 OPENCL_CL_INVALID_PROGRAM_EXECUTABLE = -45,
 OPENCL_CL_INVALID_KERNEL_NAME = -46,
 OPENCL_CL_INVALID_KERNEL_DEFINITION = -47,
 OPENCL_CL_INVALID_KERNEL = -48,
 OPENCL_CL_INVALID_ARG_INDEX = -49,
 OPENCL_CL_INVALID_ARG_VALUE = -50,
 OPENCL_CL_INVALID_ARG_SIZE = -51,
 OPENCL_CL_INVALID_KERNEL_ARGS = -52,
 OPENCL_CL_INVALID_WORK_DIMENSION = -53,
 OPENCL_CL_INVALID_WORK_GROUP_SIZE = -54,
 OPENCL_CL_INVALID_WORK_ITEM_SIZE = -55,
 OPENCL_CL_INVALID_GLOBAL_OFFSET = -56,
 OPENCL_CL_INVALID_EVENT_WAIT_LIST = -57,
 OPENCL_CL_INVALID_EVENT = -58,
 OPENCL_CL_INVALID_OPERATION = -59,
 OPENCL_CL_INVALID_GL_OBJECT = -60,
 OPENCL_CL_INVALID_BUFFER_SIZE = -61,
 OPENCL_CL_INVALID_MIP_LEVEL = -62,
 OPENCL_CL_INVALID_GLOBAL_WORK_SIZE = -63
};

}

