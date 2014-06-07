#pragma once

#include "boost.hpp"
#include "stl.hpp"

class IClIncludePreprocessor
{
public:
    virtual boost::shared_ptr<std::string> replaceIncludes( boost::shared_ptr<std::string> source,
                                                            std::set<std::string>& includeDirectories ) = 0;
};

