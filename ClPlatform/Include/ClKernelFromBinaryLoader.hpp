#ifndef __CL_KERNEL_FROM_BINARY_LOADER__
#define __CL_KERNEL_FROM_BINARY_LOADER__

#include "IClKernelFromFileLoader.hpp"

class ClKernelFromBinaryLoader : public IClKernelFromFileLoader
{
public:
    virtual boost::shared_ptr<IClKernel> loadKernel(std::string filename);
private:
    FILE *openFile(std::string& filename);
    size_t readBinarySize( FILE*, std::string& filename );
    unsigned char* readBinary( FILE*, size_t binarySize, std::string& filename );
};

#endif