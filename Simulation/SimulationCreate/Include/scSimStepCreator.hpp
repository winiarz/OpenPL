#pragma once

#include "InstructionBlock.hpp"
#include "IInstructionRecorder.hpp"
#include "scISimStepCreator.hpp"
#include "IVariable.hpp"

namespace OPL
{
namespace SimCreate
{

class SimStepCreator : public ISimStepCreator
{
public:
    SimStepCreator(boost::function<std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>()>,
                   std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>);
    virtual boost::shared_ptr<ISimStep> create();
private:
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments;
    boost::function<std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>()> recordInstructionBlock;
    boost::shared_ptr<InsPr::IInstructionRecorder> recorder;
};

}
}

