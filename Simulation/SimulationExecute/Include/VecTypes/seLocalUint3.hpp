
#ifndef __OPL_SE_LOCAL_UINT_3__
#define __OPL_SE_LOCAL_UINT_3__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalUint3 {
    public:
      uint& operator[](int);
    private:
      #if 3 == 3
      uint value[4];
      #else
      uint value[3];
      #endif
    };
  }
}

#endif
