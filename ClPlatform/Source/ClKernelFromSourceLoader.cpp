#include "ClKernelFromSourceLoader.hpp"
#include "ClPlatform.hpp"
#include "ClKernel.hpp"
#include "ClError.hpp"
#include "logs.hpp"
#include "stl.hpp"
#include "OpenClCompiler.hpp"
#include "ClIncludePreprocessor.hpp"

namespace OPL
{

ClKernelFromSourceLoader::ClKernelFromSourceLoader(std::vector<std::string>& p_includeDirectories) :
    compilerWithPreprocessor(std::make_shared<OpenClCompiler>(),
                             std::make_shared<ClIncludePreprocessor>(p_includeDirectories))
{
}

shared_ptr<ClKernel> ClKernelFromSourceLoader::loadKernel(std::string filename)
{
    shared_ptr<std::string> source = readFile(filename);

    cl_program program = compilerWithPreprocessor.compile(*source);
    return make_shared<ClKernel>(program);
}

shared_ptr<std::string> ClKernelFromSourceLoader::readFile(std::string& filename)
{
    std::ifstream file(filename);
    if ( !file.is_open() ) 
    {
        ERROR << "error while reading file " << filename;
        throw FILE_READ_ERROR;
    }

    auto text = make_shared<std::string>();

    file.seekg(0, std::ios::end);   
    text->reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    text->assign( std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>() );

    return text;
}

}

