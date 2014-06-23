#pragma once

#include <CL/cl.h>
#include "IClKernelFromFileLoader.hpp"
#include "ClIncludePreprocessor.hpp"

class ClKernelFromSourceLoader : public IClKernelFromFileLoader
{
public:
    ClKernelFromSourceLoader(std::set<std::string>);
    virtual std::shared_ptr<ClKernel> loadKernel(std::string filename);
private:
    std::shared_ptr<std::string> readFile(std::string& filename);
    cl_program compileSource(std::shared_ptr<std::string> source);

    static const unsigned int MAX_BUILD_LOG_SIZE = 16384;
    std::set<std::string> includeDirectories;
    ClIncludePreprocessor includePreprocessor;
};

