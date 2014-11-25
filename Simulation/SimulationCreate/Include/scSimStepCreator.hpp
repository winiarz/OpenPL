#pragma once

#include "InstructionBlock.hpp"
#include "IInstructionRecorder.hpp"
#include "scISimStepCreator.hpp"
#include "IVariable.hpp"
#include "OpenPlConfiguration.hpp"
#include "OpenPlConfigurationProvider.hpp"

namespace OPL
{
namespace SimCreate
{

class SimStepCreator : public ISimStepCreator
{
public:
    SimStepCreator(boost::function<std::vector<shared_ptr<InsPr::IGlobalArrayVariable>>()>,
                   std::vector<shared_ptr<InsPr::IGlobalArrayVariable>>);
    virtual shared_ptr<ISimStep> create();
private:
    std::vector<shared_ptr<InsPr::IGlobalArrayVariable>> arguments;
    boost::function<std::vector<shared_ptr<InsPr::IGlobalArrayVariable>>()> recordInstructionBlock;
    shared_ptr<InsPr::IInstructionRecorder> recorder;
    OpenPlConfigurationProvider configurationProvider;
};

}
}

