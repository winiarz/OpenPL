#pragma once

#include "stl.hpp"

class IClIncludePreprocessor
{
public:
    virtual shared_ptr<std::string> replaceIncludes( std::string& source ) = 0;
};

