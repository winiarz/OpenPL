#pragma once

#include <set>

namespace OPL
{

class ClParameter {
public:
    virtual void calculateValues(ClDeviceInfo&) = 0;
protected:
    set<int> values;
};

}

