#include "scSimStepCreator.hpp"
#include "scSingleKernelSimStep.hpp"
#include "Kernel.hpp"

namespace OPL
{
namespace SimCreate
{

SimStepCreator::SimStepCreator(boost::function<boost::shared_ptr<InsPr::InstructionBlock>()> p_createInstructionBlock,
                               std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> p_arguments) :
    arguments(p_arguments),
    createInstructionBlock(p_createInstructionBlock)
{

}

boost::shared_ptr<ISimStep> SimStepCreator::create()
{
    auto instructionBlock = createInstructionBlock();
    auto kernel = boost::make_shared<InsPr::Kernel>("kernelName",
                                                    arguments,
                                                    instructionBlock);

    return boost::make_shared<SingleKernelSimStep>(kernel);
}

}
}

