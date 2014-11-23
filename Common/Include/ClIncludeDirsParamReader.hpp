#pragma once
#include <vector>
#include <string>
#include <IConfigParamReader.hpp>

class ClIncludeDirsParamReader : public IConfigParamReader
{
public:
    ClIncludeDirsParamReader(std::vector<std::string>&);

    virtual std::string getName() override;
    virtual void readParam(std::stringstream&) override;
private:
    std::vector<std::string>& includeDirs;
};
