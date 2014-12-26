#include "seArray.hpp"
#include "seUintArray.hpp"
#include "seAdditionalTypes.hpp"

using namespace std;
using namespace OPL::SimExec;

IUintArray::IUintArray(int n) : ClArrayMemory<uint>(n)
{
}
