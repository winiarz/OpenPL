#pragma once
#include <vector>
#include <string>

class IOpenPlConfiguration
{
public:
   virtual std::vector<std::string>& getClIncludeDirs() = 0;

    virtual ~IOpenPlConfiguration() {}
};
