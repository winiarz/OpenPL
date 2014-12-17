#pragma once

#include "stl.hpp"

namespace OPL
{
class ClKernel;

class IClKernelFromFileLoader
{
public:
    virtual shared_ptr<ClKernel> loadKernel(std::string filename) = 0;
};

}

