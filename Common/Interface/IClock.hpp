#pragma once

typedef unsigned int uint;

class IClock {
public:
    virtual uint getUsec()=0;
    virtual uint getMsec()=0;
    virtual uint getSec()=0;
};

