#pragma once

#include "stl.hpp"
namespace OPL
{
class IClSingleImplementationKernel;

class IClKernelSaver
{
public:
    virtual void saveKernel( shared_ptr<IClSingleImplementationKernel> kernel, std::string filename ) = 0;
    virtual void saveKernel( shared_ptr<IClSingleImplementationKernel> kernel, FILE* file ) = 0;
};

}

