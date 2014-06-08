#include"scVariable.hpp"

using namespace std;
using namespace OPL::SimCreate;

Variable::Variable(string p_typeName) :
    simulation(*CreateKernel::getCreateKernel()),
    file(CreateKernel::getCreateKernel()->getSourceCode()),
    recorder(CreateKernel::getCreateKernel()->getRecorder())
{
  name = NameGenerator::getNameGenerator().nextName();
  typeName = p_typeName;
}

Variable::Variable(string p_name,string p_typeName) :
    simulation(*CreateKernel::getCreateKernel()),
    file(CreateKernel::getCreateKernel()->getSourceCode()),
    recorder(CreateKernel::getCreateKernel()->getRecorder())
{
  name = p_name;
  typeName = p_typeName;
}

Variable& Variable::operator=(Variable& variable)
{
    std::ostringstream sstream;
    sstream << name ;
    sstream << " = ";
    sstream << variable.name;
    boost::shared_ptr<InsPr::SingleInstruction> instruction = boost::make_shared<InsPr::SingleInstruction>( sstream.str() );
    sstream << ";\n";
    file << sstream.str();
    (*recorder) << instruction;
    return *this;
}

string Variable::getName()
{
  return name;
}
