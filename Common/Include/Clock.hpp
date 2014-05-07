#ifndef __CLOCK__
#define __CLOCK__

#include "IClock.hpp"

class Clock : public IClock {
public:
    virtual uint getUsec();
    virtual uint getMsec();
    virtual uint getSec();
};

#endif

