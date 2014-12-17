#include "clcc.hpp"
#include "ClPlatform.hpp"
#include "logs.hpp"
#include "ClKernelSaver.hpp"
#include "ClKernelFromSourceLoader.hpp"
#include "ClKernel.hpp"

int compile(const char input_file[],vector<string>  includeDirectories,const char output_file[])
{
    DEBUG << "compiling file: " << input_file;
    OPL::ClKernelFromSourceLoader kernelLoader(includeDirectories);
  
    try
    {
        shared_ptr<OPL::ClKernel> kernel = 
            kernelLoader.loadKernel(std::string(input_file));

        OPL::ClKernelSaver().saveKernel( kernel, std::string(output_file) );
    }
    catch ( OPL::ClError )
    {
        return 1;
    }

    return 0;
}
