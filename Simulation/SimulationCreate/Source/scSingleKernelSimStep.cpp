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

void SingleKernelSimStep::execute(std::vector<boost::shared_ptr<ClMemory>> args)
{
    if ( !compiledKernel ) 
    {
        std::ofstream file("__temp_source_file.cl"); // TODO - do it without temp file !!!
        file << recordedKernel->getAlternative(0);

        std::set<std::string> includeDirs = {"."};
        ClKernelFromSourceLoader loader(includeDirs);
        compiledKernel = loader.loadKernel("__temp_source_file.cl");
    }

    (*compiledKernel)(args);
}

}
}

