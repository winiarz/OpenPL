#include "seUint4Array.hpp"

using namespace OPL::SimExec;

IUint4Array::IUint4Array(int n)
    : ClArrayMemory<LocalUint4>(4 * n)
{
}
