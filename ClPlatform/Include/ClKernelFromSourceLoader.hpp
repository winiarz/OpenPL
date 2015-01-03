#pragma once
#include <vector>
#include <string>
#include "IClKernelFromFileLoader.hpp"
#include "OpenClCompilerWithPreprocessor.hpp"

namespace OPL
{

class ClKernelFromSourceLoader : public IClKernelFromFileLoader
{
public:
    ClKernelFromSourceLoader(std::vector<std::string>&);
    virtual shared_ptr<ClKernel> loadKernel(std::string filename);
private:
    shared_ptr<std::string> readFile(std::string& filename);

    OpenClCompilerWithPreprocessor compilerWithPreprocessor;
};

}

