#pragma once

#include "stl.hpp"

namespace OPL
{

class IClIncludePreprocessor
{
public:
    virtual shared_ptr<std::string> replaceIncludes( std::string& source ) = 0;
};

}

