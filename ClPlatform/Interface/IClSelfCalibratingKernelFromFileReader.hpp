#pragma once

#include "boost.hpp"
#include "stl.hpp"
#include "ClSelfCalibratingKernel.hpp"

class IClSelfCalibratingKernelFromFileReader
{
public:
    virtual boost::shared_ptr<ClSelfCalibratingKernel> read(std::string filename) = 0;
};

