#pragma once

#include <CL/cl.h>
#include "IClKernelFromFileLoader.hpp"
#include "ClIncludePreprocessor.hpp"
#include "OpenClCompiler.hpp"

class ClKernelFromSourceLoader : public IClKernelFromFileLoader
{
public:
    ClKernelFromSourceLoader(std::set<std::string>);
    virtual shared_ptr<ClKernel> loadKernel(std::string filename);
private:
    shared_ptr<std::string> readFile(std::string& filename);

    std::set<std::string> includeDirectories;
    ClIncludePreprocessor includePreprocessor;
    OpenClCompiler compiler;
};

