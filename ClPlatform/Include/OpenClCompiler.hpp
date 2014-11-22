#pragma once
#include "IOpenClCompiler.hpp"

class OpenClCompiler : public IOpenClCompiler
{
public:
    OpenClCompiler();
    virtual cl_program compile(std::string&) const override;
private:
    static const unsigned int MAX_BUILD_LOG_SIZE = 16384;
};
