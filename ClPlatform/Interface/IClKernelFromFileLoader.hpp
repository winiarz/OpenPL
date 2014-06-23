#pragma once

#include "boost.hpp"
#include "stl.hpp"

class ClKernel;

class IClKernelFromFileLoader
{
public:
    virtual std::shared_ptr<ClKernel> loadKernel(std::string filename) = 0;
};

