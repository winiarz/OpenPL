#pragma once

#include <CL/cl.h>
#include "IClKernelFromFileLoader.hpp"
#include "ClIncludePreprocessor.hpp"
#include "OpenClCompiler.hpp"
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

