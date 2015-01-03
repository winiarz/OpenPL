#pragma once

#include "stl.hpp"
#include "boost.hpp"

namespace OPL
{

class IClParameter;
class IClSingleImplementationKernel;

class IClParameterizedKernel {
public:
    virtual optional<shared_ptr<IClSingleImplementationKernel> > getKernel(int) = 0;
    virtual void rejectKernel(shared_ptr<IClSingleImplementationKernel>) = 0;
    virtual shared_ptr<IClParameter> getParameter() = 0;
    virtual shared_ptr<set<int> > getNotRejectedParameters() = 0;
};

}

