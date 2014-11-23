#pragma once
#include "IOpenPlConfigurationFileReader.hpp"
#include "IConfigParamReader.hpp"

class OpenPlConfigurationFileReader : public IOpenPlConfigurationFileReader
{
public:
    OpenPlConfigurationFileReader();

    virtual std::shared_ptr<IOpenPlConfiguration> createConfigrationFromFile(std::string) override;
private:
    std::shared_ptr<IOpenPlConfiguration> openPlConfiguration;
    std::vector<std::shared_ptr<IConfigParamReader>> paramReaders;
};
