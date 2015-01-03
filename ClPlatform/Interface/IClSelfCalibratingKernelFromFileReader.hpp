#pragma once

#include "stl.hpp"

namespace OPL
{
class ClSelfCalibratingKernel;

class IClSelfCalibratingKernelFromFileReader
{
public:
    virtual shared_ptr<ClSelfCalibratingKernel> read(std::string filename) = 0;
};

}

