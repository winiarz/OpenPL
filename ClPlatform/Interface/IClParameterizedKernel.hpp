#ifndef ICLPARAMETERIZEDKERNEL_HPP
#define ICLPARAMETERIZEDKERNEL_HPP

#include "boost.hpp"
#include "stl.hpp"

class IClKernel;
class IClParameter;

class IClParameterizedKernel {
public:
    virtual optional<shared_ptr<IClKernel> > getKernel(int) = 0;
    virtual void rejectKernel(shared_ptr<IClKernel>) = 0;
    virtual boost::shared_ptr<IClParameter> getParameter() = 0;
    virtual boost::shared_ptr<set<int> > getNotRejectedParameters() = 0;
};

#endif // ICLPARAMETERIZEDKERNEL_HPP
