#ifndef __OPL_SC_$TYPENAME_ARRAY__
#define __OPL_SC_$TYPENAME_ARRAY__

#include <sstream>
#include "scClasses.hpp"
#include "scArray.hpp"
#include "sc$TypeName.hpp"
namespace OPL

{
  namespace SimCreate
  {
    using namespace std;

    class $TypeNameArray : public Array {
    public:
      $TypeNameArray(string);
      static string getTypeName();
      
      $TypeName operator[](int);
    };
  }
}
#endif
