
#ifndef __OPL_SE_LOCAL_INT_3__
#define __OPL_SE_LOCAL_INT_3__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalInt3 {
    public:
      int& operator[](int);
    private:
      #if 3 == 3
      int value[4];
      #else
      int value[3];
      #endif
    };
  }
}

#endif
