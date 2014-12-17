#pragma once

#include "stl.hpp"
#include "ClSelfCalibratingKernel.hpp"

namespace OPL
{

class IClSelfCalibratingKernelFromFileReader
{
public:
    virtual shared_ptr<ClSelfCalibratingKernel> read(std::string filename) = 0;
};

}

