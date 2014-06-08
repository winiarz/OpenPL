#pragma once

#include "scClasses.hpp"
#include "scCreateKernel.hpp"
#include "scNameGenerator.hpp"
#include "IInstructionRecorder.hpp"
#include <string>
#include <fstream>
#include <sstream>

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class Variable {
    public:
      Variable(string);
      Variable(string,string);
      Variable& operator=(Variable&);
      string getName();
      string name;    
      CreateKernel& simulation;
      ostringstream& file;
      boost::shared_ptr<InsPr::IInstructionRecorder> recorder;
    protected:
      string typeName;
      
    };
  }
}

