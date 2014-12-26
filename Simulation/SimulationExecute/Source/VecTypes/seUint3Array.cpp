#include "seUint3Array.hpp"

using namespace OPL::SimExec;

IUint3Array::IUint3Array(int n)
    : ClArrayMemory<LocalUint3>(3 * n)
{
}
