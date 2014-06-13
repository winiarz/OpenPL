#include "scSimStepCreator.hpp"
#include "scSingleKernelSimStep.hpp"
#include "Kernel.hpp"
#include "stl.hpp"

namespace OPL
{
namespace SimCreate
{

SimStepCreator::SimStepCreator(boost::function<std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>()> p_createInstructionBlock,
                               std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> p_arguments) :
    arguments(p_arguments),
    recordInstructionBlock(p_createInstructionBlock)
{

}

boost::shared_ptr<ISimStep> SimStepCreator::create()
{
    recorder = InsPr::IVariable::recorder;
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> args = recordInstructionBlock();
    auto instructionBlock = recorder->getBlock();
    auto kernel = boost::make_shared<InsPr::Kernel>("kernelName",
                                                    args,
                                                    instructionBlock);
    return boost::make_shared<SingleKernelSimStep>(kernel);
}

}
}

