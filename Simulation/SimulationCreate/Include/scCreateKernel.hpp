#pragma once

#include <fstream>
#include <string>
#include <set>
#include <sstream>

#include "ClKernel.hpp"
#include "IInstructionRecorder.hpp"

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class CreateKernel {
    public:
      CreateKernel(const char[],const char[]);
      ~CreateKernel();
      void start(const char []);
      void addArg(string,const char[]);
      void endOfArgs();
      void createSourceFile();
      void createBinaryFile();
      void addInclude(string);
      string getName();
      string getSourceFileName();
      static string getBinaryFileName(string);
      
      static CreateKernel* actualCreateKernel;
      static CreateKernel* getCreateKernel();
      
      static ostringstream& getSourceCode();
      static boost::shared_ptr<InsPr::IInstructionRecorder> getRecorder();
      static std::string createFileName(string,string);
      
      virtual int createKernel()=0;
    protected:
      const string name;      
      const string filename;
      fstream file;
      ostringstream sourceCode;
      boost::shared_ptr<InsPr::IInstructionRecorder> recorder;
    private:
      bool firstArg;
      set<string> includes;
      set<string> includeDirectories;
      
    };
  }
}

