#include "scSimStepCreator.hpp"
#include "scSingleKernelSimStep.hpp"
#include "Kernel.hpp"
#include "stl.hpp"

namespace OPL
{
namespace SimCreate
{

SimStepCreator::SimStepCreator(boost::function<void()> p_createInstructionBlock,
                               std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> p_arguments,
                               boost::shared_ptr<InsPr::IInstructionRecorder> p_recorder) :
    arguments(p_arguments),
    recordInstructionBlock(p_createInstructionBlock),
    recorder(p_recorder)
{

}

boost::shared_ptr<ISimStep> SimStepCreator::create()
{
    recordInstructionBlock();
    auto instructionBlock = recorder->getBlock();
    auto kernel = boost::make_shared<InsPr::Kernel>("kernelName",
                                                    arguments,
                                                    instructionBlock);
    return boost::make_shared<SingleKernelSimStep>(kernel);
}

}
}

