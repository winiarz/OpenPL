
#ifndef __CL_ERROR__
#define __CL_ERROR__

enum ClError {
NO_PLATFORM,
NO_DEVICE,
KERNEL_SIZE_NOT_SET,
KERNEL_SET_ARG_ERROR,
KERNEL_EXEC_ERROR,
INTER_DEVICE_COPY_ERROR,
OUT_OF_RESOURCES
};

#endif
