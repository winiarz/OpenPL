#include "Variable.hpp"
#include "InstructionRecorder.hpp"

namespace OPL
{
namespace InsPr
{

shared_ptr<IInstructionRecorder> IVariable::recorder = make_shared<InstructionRecorder>();

}
}

