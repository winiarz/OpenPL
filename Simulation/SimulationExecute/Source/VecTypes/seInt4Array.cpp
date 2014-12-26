#include "seInt4Array.hpp"

using namespace OPL::SimExec;

IInt4Array::IInt4Array(int n)
    : ClArrayMemory<LocalInt4>(4 * n)
{
}
