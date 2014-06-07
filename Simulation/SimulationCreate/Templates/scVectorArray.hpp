
#pragma once

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

