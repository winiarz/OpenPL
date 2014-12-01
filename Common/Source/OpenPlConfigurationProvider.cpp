#include "OpenPlConfigurationProvider.hpp"
#include "OpenPlConfigurationFileReader.hpp"

bool OpenPlConfigurationProvider::isConfigLoaded;
std::shared_ptr<IOpenPlConfiguration> OpenPlConfigurationProvider::theOnlyConfiguration;

IOpenPlConfiguration& OpenPlConfigurationProvider::getOpenPlConfiguration() const
{
    if( not isConfigLoaded )
    {
        theOnlyConfiguration = OpenPlConfigurationFileReader().createConfigrationFromFile("openpl.config");
        isConfigLoaded = true;
    }
    return *theOnlyConfiguration;
}
