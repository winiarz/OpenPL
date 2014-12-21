#include "ClIncludeDirsParamReader.hpp"

namespace OPL
{

ClIncludeDirsParamReader::ClIncludeDirsParamReader(std::vector<std::string>& p_includeDirs) :
    includeDirs(p_includeDirs)
{
}

std::string ClIncludeDirsParamReader::getName()
{
    return "ClIncludeDirs";
}

void ClIncludeDirsParamReader::readParam(std::stringstream& stream)
{
    includeDirs.clear();
    std::string directory;
    while( stream >> directory )
        includeDirs.push_back(directory);
}

}
