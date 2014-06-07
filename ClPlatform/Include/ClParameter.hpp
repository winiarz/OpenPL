#pragma once

#include <set>

class ClParameter {
public:
    virtual void calculateValues(ClDeviceInfo&) = 0;
protected:
    set<int> values;
};

