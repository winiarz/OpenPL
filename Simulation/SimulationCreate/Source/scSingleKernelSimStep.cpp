#include "scSingleKernelSimStep.hpp"
#include "OpenClCompilerWithPreprocessor.hpp"
#include "OpenClCompiler.hpp"
#include "ClIncludePreprocessor.hpp"

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
        OpenClCompilerWithPreprocessor compiler(std::make_shared<OpenClCompiler>(),
                                                std::make_shared<ClIncludePreprocessor>(openPlConfiguration.getClIncludeDirs()));

        std::string sourceCode = recordedKernel->getAlternative(0);
        compiledKernel = std::make_shared<ClKernel>(compiler.compile(sourceCode));
    }
}

void SingleKernelSimStep::execute(std::vector<shared_ptr<IClMemory>> args)
{
    loadKernelIfNotLoaded();

    (*compiledKernel)[1][1](args); // TODO get optimal number of threads here
}

void SingleKernelSimStep::execute(std::vector<IClMemory*> args)
{
    loadKernelIfNotLoaded();

    (*compiledKernel)[1][1](args);
}

}
}

