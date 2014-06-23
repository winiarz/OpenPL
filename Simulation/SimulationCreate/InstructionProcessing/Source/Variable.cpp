#include "Variable.hpp"
#include "InstructionRecorder.hpp"

namespace InsPr
{
std::shared_ptr<IInstructionRecorder> IVariable::recorder = std::make_shared<InstructionRecorder>();
}

