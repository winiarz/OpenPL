#pragma once
#include <string>
#include <sstream>

class IConfigParamReader
{
public:
    virtual std::string getName() = 0;
    virtual void readParam(std::stringstream&) = 0;
};
