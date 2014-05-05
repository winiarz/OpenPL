
#ifndef __OPL_SC_$TYPENAME_$LENGTH__
#define __OPL_SC_$TYPENAME_$LENGTH__

#include <string>
#include <fstream>
#include <sstream>
#include "scVariable.hpp"
#include "sc$TypeName.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class $TypeName$LENGTH : public Variable {
    public:
      $TypeName$LENGTH();
      $TypeName$LENGTH(string);
      static string getName();
      
      $TypeName$LENGTH operator=($TypeName$LENGTH);
      
      $TypeName$LENGTH operator+($TypeName$LENGTH);
      $TypeName$LENGTH operator-($TypeName$LENGTH);
      
      $TypeName$LENGTH operator*($TypeName);
      $TypeName$LENGTH operator/($TypeName);
      
      $TypeName operator*($TypeName$LENGTH);
#if $LENGTH == 3
      $TypeName$LENGTH operator^($TypeName$LENGTH);
#endif
    };
    
    $TypeName$LENGTH operator*($TypeName,$TypeName$LENGTH);
  }
}

#endif
