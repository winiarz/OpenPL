#include "ClPlatform.hpp"
#include "scSimulationCreate.hpp"
#include "logs.hpp"
#include "SingleInstruction.hpp"
using namespace OPL::SimCreate;

InsPr::MatrixFloat3x3 Simulation::invert(InsPr::MatrixFloat3x3 m)
{
  ostringstream variableName;
  variableName << "invertMatrix3x3(" << m.getName() << ") ";
  return InsPr::MatrixFloat3x3(variableName.str());
}

