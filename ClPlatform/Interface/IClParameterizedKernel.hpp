#pragma once

#include "boost.hpp"
#include "stl.hpp"
#include "IClSingleImplementationKernel.hpp"

class IClParameter;

class IClParameterizedKernel {
public:
    virtual optional<shared_ptr<IClSingleImplementationKernel> > getKernel(int) = 0;
    virtual void rejectKernel(shared_ptr<IClSingleImplementationKernel>) = 0;
    virtual boost::shared_ptr<IClParameter> getParameter() = 0;
    virtual boost::shared_ptr<set<int> > getNotRejectedParameters() = 0;
};

