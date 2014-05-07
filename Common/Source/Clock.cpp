#include "Clock.hpp"
#include <sys/time.h>
#include <stdio.h>

uint Clock::getUsec()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint)1000000+tv.tv_usec;
}

uint Clock::getMsec()
{
    return getUsec()/1000;
}

uint Clock::getSec()
{
    return getUsec()/1000000;
}

