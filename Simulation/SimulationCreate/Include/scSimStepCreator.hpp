#pragma once

#include "InstructionBlock.hpp"
#include "InstructionRecorder.hpp"
#include "scISimStepCreator.hpp"
#include "IVariable.hpp"

namespace OPL
{
namespace SimCreate
{

class SimStepCreator : public ISimStepCreator
{
public:
    SimStepCreator(boost::function<boost::shared_ptr<InsPr::InstructionBlock>()>,
                   std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>);
    virtual boost::shared_ptr<ISimStep> create();
private:
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments;
    boost::function<boost::shared_ptr<InsPr::InstructionBlock>()> createInstructionBlock;
};

}
}

