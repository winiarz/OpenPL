
#ifndef __OPL_SC_$TYPENAME_$LENGTH_ARRAY__
#define __OPL_SC_$TYPENAME_$LENGTH_ARRAY__

#include <string>
#include <fstream>
#include <sstream>
#include "sc$TypeName$LENGTH.hpp"
#include "scArray.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class $TypeName$LENGTHArray : public Array {
    public:
      $TypeName$LENGTHArray(string);
      static string getTypeName();
      
      $TypeName$LENGTH operator[](int);
    };
  }
}

#endif
