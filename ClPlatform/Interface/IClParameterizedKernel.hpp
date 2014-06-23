#pragma once

#include "stl.hpp"
#include "boost.hpp"
#include "IClSingleImplementationKernel.hpp"

class IClParameter;

class IClParameterizedKernel {
public:
    virtual optional<std::shared_ptr<IClSingleImplementationKernel> > getKernel(int) = 0;
    virtual void rejectKernel(std::shared_ptr<IClSingleImplementationKernel>) = 0;
    virtual std::shared_ptr<IClParameter> getParameter() = 0;
    virtual std::shared_ptr<set<int> > getNotRejectedParameters() = 0;
};

