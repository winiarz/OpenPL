#ifndef __CL_PARAMETER_HPP__
#define __CL_PARAMETER_HPP__

#include <set>

class ClParameter {
public:
    virtual void calculateValues(ClDeviceInfo&) = 0;
protected:
    set<int> values;
};

#endif // CLPARAMETER_HPP
