#include"scVariable.hpp"

using namespace std;
using namespace OPL::SimCreate;

Variable::Variable(string p_typeName) : simulation(*CreateKernel::getCreateKernel()),  file(CreateKernel::getCreateKernel()->getSourceCode())
{
  name = NameGenerator::getNameGenerator().nextName();
  typeName = p_typeName;
}

Variable::Variable(string p_name,string p_typeName) : simulation(*CreateKernel::getCreateKernel()), file(CreateKernel::getCreateKernel()->getSourceCode())
{
  name = p_name;
  typeName = p_typeName;
}

Variable& Variable::operator=(Variable& variable)
{
  file << name ;
  file << " = ";
  file << variable.name << ";\n";
  return *this;
}

string Variable::getName()
{
  return name;
}
