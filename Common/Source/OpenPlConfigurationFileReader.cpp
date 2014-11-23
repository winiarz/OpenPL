#include"OpenPlConfigurationFileReader.hpp"
#include"OpenPlConfiguration.hpp"
#include"ClIncludeDirsParamReader.hpp"
#include<fstream>
#include <vector>
#include <sstream>

OpenPlConfigurationFileReader::OpenPlConfigurationFileReader()
{
    openPlConfiguration = std::make_shared<OpenPlConfiguration>();

    paramReaders.push_back( std::make_shared<ClIncludeDirsParamReader>(openPlConfiguration->getClIncludeDirs()) );
}

std::shared_ptr<IOpenPlConfiguration> OpenPlConfigurationFileReader::createConfigrationFromFile(std::string fileName)
{
    std::ifstream configFile(fileName);

    while(!configFile.eof())
    {
        const int maxLineLength = 1024;
        std::vector<char> line(maxLineLength);
        configFile.getline(line.data(), maxLineLength);

        std::stringstream sstream(line.data());

        std::string paramName;
        sstream >> paramName;
    }
    return std::make_shared<OpenPlConfiguration>();
}
