#include "Variable.hpp"
#include "InstructionRecorder.hpp"

namespace InsPr
{
boost::shared_ptr<IInstructionRecorder> IVariable::recorder = boost::make_shared<InstructionRecorder>();
}

