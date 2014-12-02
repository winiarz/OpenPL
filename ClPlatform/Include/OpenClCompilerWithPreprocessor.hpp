#pragma once
#include "IOpenClCompiler.hpp"
#include "IClIncludePreprocessor.hpp"

class OpenClCompilerWithPreprocessor : public IOpenClCompiler
{
public:
    OpenClCompilerWithPreprocessor(std::shared_ptr<IOpenClCompiler>,
                                   std::shared_ptr<IClIncludePreprocessor>);
                                   
    virtual cl_program compile(std::string&) const override;
private:
    std::shared_ptr<IOpenClCompiler> baseCompiler;
    std::shared_ptr<IClIncludePreprocessor> includePreprocessor;
};

