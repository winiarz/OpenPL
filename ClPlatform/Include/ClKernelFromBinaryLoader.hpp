#pragma once

#include "IClKernelFromFileLoader.hpp"

namespace OPL
{

class ClKernelFromBinaryLoader : public IClKernelFromFileLoader
{
public:
    shared_ptr<OPL::ClKernel> loadKernel(std::string filename);
    shared_ptr<OPL::ClKernel> loadKernel( FILE* );
private:
    FILE *openFile(std::string& filename);
    size_t readBinarySize( FILE* );
    unsigned char* readBinary( FILE*, size_t binarySize );
};

}

