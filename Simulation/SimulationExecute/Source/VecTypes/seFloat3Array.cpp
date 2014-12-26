#include "seFloat3Array.hpp"

using namespace OPL::SimExec;

IFloat3Array::IFloat3Array(int n)
    : ClArrayMemory<LocalFloat3>(3 * n)
{
}
