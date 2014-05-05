
#ifndef __OPL_SC_TYPE__
#define __OPL_SC_TYPE__

#include <string>

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class Type {
      Type(string);
    private:
      string typeName;
    };
  }
}

#endif
