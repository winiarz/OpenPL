#pragma once

#include "IClock.hpp"

namespace OPL
{

class Clock : public IClock {
public:
    virtual uint getUsec();
    virtual uint getMsec();
    virtual uint getSec();
};

}
