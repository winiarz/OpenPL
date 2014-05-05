#include "seMaterialPointArray.hpp"
using namespace OPL::SimExec;

IMaterialPointArray::IMaterialPointArray(int n) : ClTypedMemory<LocalMaterialPoint>(n)
{
}
