#pragma once
#include "IOpenPlConfiguration.hpp"

namespace OPL
{

class OpenPlConfiguration : public IOpenPlConfiguration
{
public:
    OpenPlConfiguration();
    virtual std::vector<std::string>& getClIncludeDirs() override;

private:
    std::vector<std::string> clIncludeDirs;
};

}
