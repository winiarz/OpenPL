#include "OpenPlConfigurationProvider.hpp"
#include "OpenPlConfiguration.hpp"


IOpenPlConfiguration& OpenPlConfigurationProvider::getOpenPlConfiguration() const
{
    static OpenPlConfiguration theOnlyConfiguration;
    return theOnlyConfiguration;
}
