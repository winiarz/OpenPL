#pragma once
#include "IOpenPlConfiguration.hpp"

class OpenPlConfiguration : public IOpenPlConfiguration
{
public:
   virtual std::set<std::string> getClIncludeDirs() const override;
};
