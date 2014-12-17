#pragma once

#include "IClParameterizedKernel.hpp"

namespace OPL
{

class ClParameterizedKernel : public IClParameterizedKernel {
public:
    ClParameterizedKernel(shared_ptr<IClParameter>);
    virtual optional<shared_ptr<OPL::IClSingleImplementationKernel> > getKernel(int);
    virtual void rejectKernel(shared_ptr<OPL::IClSingleImplementationKernel>);
    virtual shared_ptr<IClParameter> getParameter();
    virtual shared_ptr<set<int> > getNotRejectedParameters();

    virtual string getSource(int) = 0;
    virtual string getKernelName() = 0;
private:
    shared_ptr<IClParameter> parameter;
    set<int> rejectedKernels;
    map<int,shared_ptr<OPL::IClSingleImplementationKernel> > builtKernels;
};

}

