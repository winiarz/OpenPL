#include "seArray.hpp"
#include "seFloatArray.hpp"
#include "seAdditionalTypes.hpp"

using namespace std;
using namespace OPL::SimExec;

IFloatArray::IFloatArray(int n) : ClArrayMemory<float>(n)
{
}
