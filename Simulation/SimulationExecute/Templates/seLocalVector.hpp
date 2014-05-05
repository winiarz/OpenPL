
#ifndef __OPL_SE_LOCAL_$TYPENAME_$LENGTH__
#define __OPL_SE_LOCAL_$TYPENAME_$LENGTH__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class Local$TypeName$LENGTH {
    public:
      $typename& operator[](int);
    private:
      #if $LENGTH == 3
      $typename value[4];
      #else
      $typename value[$LENGTH];
      #endif
    };
  }
}

#endif
