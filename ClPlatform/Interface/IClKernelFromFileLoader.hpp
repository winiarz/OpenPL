#pragma once
#include <memory>
using std::shared_ptr;

namespace OPL
{
class ClKernel;

class IClKernelFromFileLoader
{
public:
    virtual shared_ptr<ClKernel> loadKernel(std::string filename) = 0;
};

}

