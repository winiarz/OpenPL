#pragma once

#include "stl.hpp"

namespace OPL
{
class ClKernel;
}

class IClKernelFromFileLoader
{
public:
    virtual shared_ptr<OPL::ClKernel> loadKernel(std::string filename) = 0;
};

