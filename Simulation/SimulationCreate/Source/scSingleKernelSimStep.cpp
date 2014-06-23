#include "scSingleKernelSimStep.hpp"
#include "ClKernelFromSourceLoader.hpp"

namespace OPL
{
namespace SimCreate
{

SingleKernelSimStep::SingleKernelSimStep(boost::shared_ptr<InsPr::IKernel> p_recordedKernel) :
    recordedKernel(p_recordedKernel),
    compiledKernel()
{
}

void SingleKernelSimStep::loadKernelIfNotLoaded()
{
    if ( !compiledKernel ) 
    {
        std::ofstream file("__temp_source_file.cl"); // TODO - do it without temp file !!!
        file << recordedKernel->getAlternative(0);
        file.close();

        std::set<std::string> includeDirs = {".","/media/DATA/OpenPL/OpenPL/clinclude"};
        ClKernelFromSourceLoader loader(includeDirs);
        compiledKernel = loader.loadKernel("__temp_source_file.cl");
    }
}

void SingleKernelSimStep::execute(std::vector<std::shared_ptr<ClMemory>> args)
{
    loadKernelIfNotLoaded();

    (*compiledKernel)[1][1](args);
}

void SingleKernelSimStep::execute(std::vector<ClMemory*> args)
{
    loadKernelIfNotLoaded();

    (*compiledKernel)[1][1](args);
}

}
}

