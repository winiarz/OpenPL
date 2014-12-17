#include "OpenClCompilerWithPreprocessor.hpp"

namespace OPL
{

OpenClCompilerWithPreprocessor::OpenClCompilerWithPreprocessor(std::shared_ptr<IOpenClCompiler> p_baseCompiler,
                                                               std::shared_ptr<IClIncludePreprocessor> p_includePreprocessor) :
    baseCompiler(p_baseCompiler),
    includePreprocessor(p_includePreprocessor)
{}

cl_program OpenClCompilerWithPreprocessor::compile(std::string& sourceCode) const
{
    auto sourceWithReplacedIncludes = includePreprocessor->replaceIncludes(sourceCode);
    return baseCompiler->compile(*sourceWithReplacedIncludes);
}

}

