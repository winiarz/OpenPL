#include "seInt3Array.hpp"

using namespace OPL::SimExec;

IInt3Array::IInt3Array(int n)
    : ClArrayMemory<LocalInt3>(3 * n)
{
}
