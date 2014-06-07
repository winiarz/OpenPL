#pragma once

#include "IClock.hpp"

class Clock : public IClock {
public:
    virtual uint getUsec();
    virtual uint getMsec();
    virtual uint getSec();
};

