#include "clcc.hpp"
#include "ClPlatform.hpp"
#include "logs.hpp"
#include "ClKernelSaver.hpp"
#include "ClKernelFromSourceLoader.hpp"
#include "ClKernel.hpp"

int compile(const char input_file[],set<string>  includeDirectories,const char output_file[])
{
    char temporary_file[200] = "__CLLC_TEMP_COMPILATION_FILE.cl";
    findInclude(input_file,temporary_file,includeDirectories);
  
    ClKernelFromSourceLoader kernelLoader;
  
    try
    {
        boost::shared_ptr<ClKernel> kernel = 
            kernelLoader.loadKernel(std::string(temporary_file));

        ClKernelSaver().saveKernel( kernel, std::string(output_file) );
    }
    catch ( ClError ) 
    {
        remove(temporary_file);
        return 1;
    }

    remove(temporary_file);
    return 0;
}
