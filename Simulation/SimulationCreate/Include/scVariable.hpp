
#ifndef __OPL_SC_VARIABLE__
#define __OPL_SC_VARIABLE__

#include "scClasses.hpp"
#include "scCreateKernel.hpp"
#include "scNameGenerator.hpp"
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
    protected:
      string typeName;
      
    };
  }
}

#endif