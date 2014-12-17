#pragma once

#include "ClParameterizedKernel.hpp"

namespace OPL
{

class ClParameterizedKernelFromSource : public ClParameterizedKernel {
public:
    ClParameterizedKernelFromSource(shared_ptr<IClParameter>,string,string,string);

    virtual string getSource(int);
    virtual string getKernelName();
private:
    bool setupSuccessfully;
    string fileName;
    string kernelName;
    string paramName;
};

}

