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
    SimStepCreator(boost::function<void()>,
                   std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>,
                   boost::shared_ptr<InsPr::IInstructionRecorder>);
    virtual boost::shared_ptr<ISimStep> create();
private:
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments;
    boost::function<void()> recordInstructionBlock;
    boost::shared_ptr<InsPr::IInstructionRecorder> recorder;
};

}
}

