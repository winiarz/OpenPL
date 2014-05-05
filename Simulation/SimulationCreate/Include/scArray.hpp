
#ifndef __OPL_SC_ARRAY__
#define __OPL_SC_ARRAY__

#include <string>
#include <fstream>
#include <sstream>

#include "scClasses.hpp"
#include "scVariable.hpp"
#include "scType.hpp"

namespace OPL
{
  namespace SimCreate
  {
      
    class Array {
    public:
      Array(string);
      Array(string,string);
      ~Array(){}
      string name;
      ostringstream& file;
      CreateKernel& simulation;
    protected:
      string typeName;
      
    };
  }
}

#endif
