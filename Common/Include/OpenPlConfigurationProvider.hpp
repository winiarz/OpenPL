#pragma once

#include <memory>
#include "IOpenPlConfigurationProvider.hpp"
#include "IOpenPlConfiguration.hpp"

namespace OPL
{

class OpenPlConfigurationProvider : public IOpenPlConfigurationProvider
{
public:
    IOpenPlConfiguration& getOpenPlConfiguration() const override;
private:
    static bool isConfigLoaded;
    static std::shared_ptr<IOpenPlConfiguration> theOnlyConfiguration;
};

}
