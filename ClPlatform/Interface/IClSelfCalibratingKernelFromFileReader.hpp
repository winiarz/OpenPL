#pragma once

#include "stl.hpp"
#include "ClSelfCalibratingKernel.hpp"

class IClSelfCalibratingKernelFromFileReader
{
public:
    virtual std::shared_ptr<ClSelfCalibratingKernel> read(std::string filename) = 0;
};

