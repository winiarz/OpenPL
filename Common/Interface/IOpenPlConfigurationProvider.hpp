#pragma once

#include "IOpenPlConfiguration.hpp"

class IOpenPlConfigurationProvider
{
public:
    virtual IOpenPlConfiguration& getOpenPlConfiguration() const = 0;
};
