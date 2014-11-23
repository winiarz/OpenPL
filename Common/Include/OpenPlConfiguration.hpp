#pragma once
#include "IOpenPlConfiguration.hpp"

class OpenPlConfiguration : public IOpenPlConfiguration
{
public:
    OpenPlConfiguration();
    virtual std::vector<std::string>& getClIncludeDirs() override;

private:
    std::vector<std::string> clIncludeDirs;
};
