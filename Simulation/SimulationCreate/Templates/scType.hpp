#ifndef __OPL_SC_$TYPENAME__
#define __OPL_SC_$TYPENAME__

#include <string>
#include <fstream>
#include <sstream>
#include "scVariable.hpp"
#include "scAdditionalTypes.hpp"
#include "scNameGenerator.hpp"

#include "scBool.hpp"

namespace OPL

{
  namespace SimCreate
  {
    using namespace std;

    class $TypeName : public Variable {
    public:
      $TypeName();
      $TypeName(string);
      static string getName();
      
      $TypeName( $typename );
      
      $TypeName operator=($TypeName);
      $TypeName operator+($TypeName);
      $TypeName operator-($TypeName);
      $TypeName operator*($TypeName);
      $TypeName operator/($TypeName);
      $TypeName operator%($TypeName);
      
      Bool operator<($TypeName);
      Bool operator>($TypeName);
      Bool operator<=($TypeName);
      Bool operator>=($TypeName);
    };
  }
}
#endif
