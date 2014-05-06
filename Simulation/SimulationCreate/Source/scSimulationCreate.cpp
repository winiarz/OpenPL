#include "scSimulationCreate.hpp"
#include "clcc.hpp"
using namespace OPL::SimCreate;

CreateKernel* CreateKernel::actualCreateKernel;



CreateKernel::CreateKernel(const char simulation_name[], const char kernel_name[]) : name(kernel_name), filename( createFileName(simulation_name, kernel_name) )
{
  includeDirectories.insert( "." );
  includeDirectories.insert( "/media/DATA/OpenPL/OpenPL/clinclude" ); // TODO remove this hardcoding !!!
}

void CreateKernel::start(const char kernel_name[])
{
  sourceCode << "__kernel void " << kernel_name << "(";
  firstArg = true;
  actualCreateKernel = this;
}

void CreateKernel::addArg(string argType,const char argName[])
{
  if(!firstArg)
    sourceCode << ", ";
  sourceCode << "__global " << argType << "* " << argName;
  firstArg = false;
}

void CreateKernel::endOfArgs()
{
  sourceCode << ")\n";
  sourceCode << "{\n";
    
  firstArg = true;
}

CreateKernel::~CreateKernel()
{
  
}

string CreateKernel::createFileName(string simulation_name,string kernel_name)
{
  string fileName(simulation_name);
  fileName.append("_");
  fileName.append(kernel_name);
  fileName.append(".cl");
  return fileName;
}

void CreateKernel::createSourceFile()
{
  sourceCode << "}\n";
  
  file.open(filename.c_str(), ios::out );
  for(set<string>::iterator i=includes.begin(); i!= includes.end(); i++)
  {
    file << "#include\"" << *i << "\"\n";
  }
  file << sourceCode.str();
  file.close();
}

void CreateKernel::addInclude(string includeFileName)
{
  includes.insert(includeFileName);
}

CreateKernel* CreateKernel::getCreateKernel()
{
  return actualCreateKernel;
}

ostringstream& CreateKernel::getSourceCode()
{
  return actualCreateKernel->sourceCode;
}

void CreateKernel::createBinaryFile()
{
  createSourceFile();
  string binaryFileName = filename;
  binaryFileName.append("bin");
  compile(filename.c_str(),includeDirectories, binaryFileName.c_str());
  remove(filename.c_str());
}

string CreateKernel::getName()
{
  return name;
}

string CreateKernel::getSourceFileName()
{
  return filename;
}

string CreateKernel::getBinaryFileName(string sourceFileName)
{
  string binaryFileName = sourceFileName;
  binaryFileName.append("bin");
  return binaryFileName;
}

