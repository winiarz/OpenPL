#pragma once

#include "IClKernelFromFileLoader.hpp"

class ClKernelFromBinaryLoader : public IClKernelFromFileLoader
{
public:
    shared_ptr<ClKernel> loadKernel(std::string filename);
    shared_ptr<ClKernel> loadKernel( FILE* );
private:
    FILE *openFile(std::string& filename);
    size_t readBinarySize( FILE* );
    unsigned char* readBinary( FILE*, size_t binarySize );
};

