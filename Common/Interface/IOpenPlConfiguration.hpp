#pragma once
#include <set>
#include <string>

class IOpenPlConfiguration
{
public:
   virtual std::set<std::string> getClIncludeDirs() const = 0;

    virtual ~IOpenPlConfiguration() {};
};
