#include "seArray.hpp"
#include "seIntArray.hpp"
#include "seAdditionalTypes.hpp"

using namespace std;
using namespace OPL::SimExec;

IIntArray::IIntArray(int n) : ClArrayMemory<int>(n)
{
}
