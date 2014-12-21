#include "OpenPlConfiguration.hpp"

namespace OPL
{

OpenPlConfiguration::OpenPlConfiguration()
{
}

std::vector<std::string>& OpenPlConfiguration::getClIncludeDirs()
{
    return clIncludeDirs;
}

}
