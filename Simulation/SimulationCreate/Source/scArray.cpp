#include "scArray.hpp"

using namespace std;
using namespace OPL::SimCreate;

Array::Array(string p_typeName) 
    : file(CreateKernel::getCreateKernel()->getSourceCode()), simulation(*CreateKernel::getCreateKernel())
{
  name = NameGenerator::getNameGenerator().nextName();
  typeName = p_typeName;
}

Array::Array(string p_name,string p_typeName) 
    : file(CreateKernel::getCreateKernel()->getSourceCode()), simulation(*CreateKernel::getCreateKernel())
{
  name = p_name;
  typeName = p_typeName;
}

