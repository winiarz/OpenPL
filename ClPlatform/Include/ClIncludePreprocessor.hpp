#pragma once

#include "IClIncludePreprocessor.hpp"

class ClIncludePreprocessor : public IClIncludePreprocessor
{
public:
    ClIncludePreprocessor(std::vector<std::string>&);

    virtual shared_ptr<std::string> replaceIncludes( shared_ptr<std::string> source) override;
private:
    std::set<std::string> includedFilePaths;
    std::vector<std::string>& includeDirs;

    bool isLineIncludeDirective( std::string& line );
    std::string getIncludeFilename( std::string& line );
    shared_ptr<std::string> readFile(std::string& filename);
    std::string getIncludeFilePath(std::string&);
};

