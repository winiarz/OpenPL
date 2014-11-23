#include "OpenPlConfiguration.hpp"

OpenPlConfiguration::OpenPlConfiguration()
{
    clIncludeDirs.push_back(".");
    clIncludeDirs.push_back("/home/winiarz/OpenPL/clinclude");
}

std::vector<std::string>& OpenPlConfiguration::getClIncludeDirs()
{
    return clIncludeDirs;
}
