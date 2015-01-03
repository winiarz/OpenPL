#pragma once

#include <set>

namespace OPL
{
class ClDeviceInfo;

class ClParameter {
public:
    virtual void calculateValues(ClDeviceInfo&) = 0;
protected:
    std::set<int> values;
};

}

