#ifndef __I_CLOCK__
#define __I_CLOCK__

typedef unsigned int uint;

class IClock {
public:
    virtual uint getUsec()=0;
    virtual uint getMsec()=0;
    virtual uint getSec()=0;
};

#endif

