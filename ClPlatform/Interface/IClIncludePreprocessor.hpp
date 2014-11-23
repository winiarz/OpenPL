#pragma once

#include "stl.hpp"

class IClIncludePreprocessor
{
public:
    virtual shared_ptr<std::string> replaceIncludes( shared_ptr<std::string> source,
                                                     std::vector<std::string>& includeDirectories ) = 0;
};

