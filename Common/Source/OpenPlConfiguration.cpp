#include "OpenPlConfiguration.hpp"

OpenPlConfiguration::OpenPlConfiguration()
{
}

std::vector<std::string>& OpenPlConfiguration::getClIncludeDirs()
{
    return clIncludeDirs;
}
