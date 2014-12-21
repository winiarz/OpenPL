#pragma once

#include "IOpenPlConfiguration.hpp"

namespace OPL
{

class IOpenPlConfigurationProvider
{
public:
    virtual IOpenPlConfiguration& getOpenPlConfiguration() const = 0;
};

}
