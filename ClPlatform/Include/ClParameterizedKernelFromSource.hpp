#ifndef CLPARAMETERIZEDKERNELFROMSOURCE_HPP
#define CLPARAMETERIZEDKERNELFROMSOURCE_HPP

#include "ClParameterizedKernel.hpp"

class ClParameterizedKernelFromSource : public ClParameterizedKernel {
public:
    ClParameterizedKernelFromSource(std::shared_ptr<IClParameter>,string,string,string);

    virtual string getSource(int);
    virtual string getKernelName();
private:
    bool setupSuccessfully;
    string fileName;
    string kernelName;
    string paramName;
};

#endif // CLPARAMETERIZEDKERNELFROMSOURCE_HPP
