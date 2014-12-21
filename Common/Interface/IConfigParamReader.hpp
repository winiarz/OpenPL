#pragma once
#include <string>
#include <sstream>

namespace OPL
{

class IConfigParamReader
{
public:
    virtual std::string getName() = 0;
    virtual void readParam(std::stringstream&) = 0;
};

}
