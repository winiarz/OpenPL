#pragma once

#include "IOpenPlConfigurationProvider.hpp"

class OpenPlConfigurationProvider : public IOpenPlConfigurationProvider
{
public:
    IOpenPlConfiguration& getOpenPlConfiguration() const override;
};
