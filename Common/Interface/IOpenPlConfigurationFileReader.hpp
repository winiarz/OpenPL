#pragma once
#include<string>
#include <memory>
#include"IOpenPlConfiguration.hpp"

class IOpenPlConfigurationFileReader
{
public:
    virtual std::shared_ptr<IOpenPlConfiguration> createConfigrationFromFile(std::string) = 0;
};
