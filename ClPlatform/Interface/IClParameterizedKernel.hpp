#pragma once

#include "stl.hpp"
#include "boost.hpp"
#include "IClSingleImplementationKernel.hpp"

namespace OPL
{

class IClParameter;

class IClParameterizedKernel {
public:
    virtual optional<shared_ptr<OPL::IClSingleImplementationKernel> > getKernel(int) = 0;
    virtual void rejectKernel(shared_ptr<OPL::IClSingleImplementationKernel>) = 0;
    virtual shared_ptr<IClParameter> getParameter() = 0;
    virtual shared_ptr<set<int> > getNotRejectedParameters() = 0;
};

}

