#pragma once

#include "IClParameterizedKernel.hpp"

class ClParameterizedKernel : public IClParameterizedKernel {
public:
    ClParameterizedKernel(shared_ptr<IClParameter>);
    virtual optional<shared_ptr<IClSingleImplementationKernel> > getKernel(int);
    virtual void rejectKernel(shared_ptr<IClSingleImplementationKernel>);
    virtual shared_ptr<IClParameter> getParameter();
    virtual shared_ptr<set<int> > getNotRejectedParameters();

    virtual string getSource(int) = 0;
    virtual string getKernelName() = 0;
private:
    shared_ptr<IClParameter> parameter;
    set<int> rejectedKernels;
    map<int,shared_ptr<IClSingleImplementationKernel> > builtKernels;
};

