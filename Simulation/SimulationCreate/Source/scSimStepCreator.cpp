#include "scSimStepCreator.hpp"
#include "scSingleKernelSimStep.hpp"
#include "Kernel.hpp"
#include "stl.hpp"

namespace OPL
{
namespace SimCreate
{

SimStepCreator::SimStepCreator(boost::function<std::vector<shared_ptr<InsPr::IGlobalArrayVariable>>()> p_createInstructionBlock,
                               std::vector<shared_ptr<InsPr::IGlobalArrayVariable>> p_arguments) :
    arguments(p_arguments),
    recordInstructionBlock(p_createInstructionBlock)
{

}

shared_ptr<ISimStep> SimStepCreator::create()
{
    recorder = InsPr::IVariable::recorder;
    std::vector<shared_ptr<InsPr::IGlobalArrayVariable>> args = recordInstructionBlock();
    auto instructionBlock = recorder->getBlock();

    std::vector<std::string> requiredIncludes = recorder->getIncludes();
    for ( auto& arg : args) 
    {
        std::vector<std::string> includesForArg = arg->getRequiredIncludes();
        requiredIncludes.insert( requiredIncludes.end(), includesForArg.begin(), includesForArg.end() );
    }
    auto kernel = make_shared<InsPr::Kernel>("kernelName",
                                             args,
                                             instructionBlock,
                                             requiredIncludes);

    return make_shared<SingleKernelSimStep>(kernel,
                                            configurationProvider.getOpenPlConfiguration());
}

}
}

