#pragma once

class IClKernelCallStats
{
public:
    virtual void registerCall() = 0;
    virtual float getScore() = 0;
};

