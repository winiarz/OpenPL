#pragma once

#include "IClParameterizedKernel.hpp"

class ClParameterizedKernel : public IClParameterizedKernel {
public:
    ClParameterizedKernel(boost::shared_ptr<IClParameter>);
    virtual optional<std::shared_ptr<IClSingleImplementationKernel> > getKernel(int);
    virtual void rejectKernel(std::shared_ptr<IClSingleImplementationKernel>);
    virtual boost::shared_ptr<IClParameter> getParameter();
    virtual std::shared_ptr<set<int> > getNotRejectedParameters();

    virtual string getSource(int) = 0;
    virtual string getKernelName() = 0;
private:
    boost::shared_ptr<IClParameter> parameter;
    set<int> rejectedKernels;
    map<int,std::shared_ptr<IClSingleImplementationKernel> > builtKernels;
};

