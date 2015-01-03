#pragma once
#include <string>
#include <memory>
using std::shared_ptr;

namespace OPL
{

class IClIncludePreprocessor
{
public:
    virtual shared_ptr<std::string> replaceIncludes( std::string& source ) = 0;
};

}

