#include "Variable.hpp"
#include "InstructionRecorder.hpp"

namespace InsPr
{
std::mutex IVariable::lastRecorderMutex;
std::unique_lock<std::mutex>* IVariable::lastRecorderLock = NULL;
boost::shared_ptr<IInstructionRecorder> IVariable::lastRecorder = boost::make_shared<InstructionRecorder>();
}

