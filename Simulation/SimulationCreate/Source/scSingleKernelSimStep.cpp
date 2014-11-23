#include "scSingleKernelSimStep.hpp"
#include "ClKernelFromSourceLoader.hpp"

namespace OPL
{
namespace SimCreate
{

SingleKernelSimStep::SingleKernelSimStep(shared_ptr<InsPr::IKernel> p_recordedKernel,
                                         IOpenPlConfiguration& p_openPlConfiguration) :
    recordedKernel(p_recordedKernel),
    compiledKernel(),
    openPlConfiguration(p_openPlConfiguration)
{
}

void SingleKernelSimStep::loadKernelIfNotLoaded()
{
    if ( !compiledKernel ) 
    {
        std::ofstream file("__temp_source_file.cl"); // TODO - do it without temp file !!!
        file << recordedKernel->getAlternative(0);
        file.close();

        ClKernelFromSourceLoader loader(openPlConfiguration.getClIncludeDirs());
        compiledKernel = loader.loadKernel("__temp_source_file.cl");
    }
}

void SingleKernelSimStep::execute(std::vector<shared_ptr<ClMemory>> args)
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

