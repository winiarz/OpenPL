#ifndef CLPARAMETERIZEDKERNEL_HPP
#define CLPARAMETERIZEDKERNEL_HPP

#include "IClParameterizedKernel.hpp"

class ClParameterizedKernel : public IClParameterizedKernel {
public:
    ClParameterizedKernel(boost::shared_ptr<IClParameter>);
    virtual optional<shared_ptr<IClSingleImplementationKernel> > getKernel(int);
    virtual void rejectKernel(shared_ptr<IClSingleImplementationKernel>);
    virtual boost::shared_ptr<IClParameter> getParameter();
    virtual boost::shared_ptr<set<int> > getNotRejectedParameters();

    virtual string getSource(int) = 0;
    virtual string getKernelName() = 0;
private:
    boost::shared_ptr<IClParameter> parameter;
    set<int> rejectedKernels;
    map<int,boost::shared_ptr<IClSingleImplementationKernel> > builtKernels;
};

#endif // CLPARAMETERIZEDKERNEL_HPP
