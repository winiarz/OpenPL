#include "seFloat4Array.hpp"

using namespace OPL::SimExec;

IFloat4Array::IFloat4Array(int n)
    : ClArrayMemory<LocalFloat4>(4 * n)
{
}
