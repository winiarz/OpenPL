#pragma once

#include "IClKernelFromFileLoader.hpp"

class ClKernelFromBinaryLoader : public IClKernelFromFileLoader
{
public:
    virtual boost::shared_ptr<ClKernel> loadKernel(std::string filename);
		boost::shared_ptr<ClKernel> loadKernel( FILE* );
private:
    FILE *openFile(std::string& filename);
    size_t readBinarySize( FILE* );
    unsigned char* readBinary( FILE*, size_t binarySize );
};

