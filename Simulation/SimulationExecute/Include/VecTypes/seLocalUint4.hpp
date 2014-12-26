
#ifndef __OPL_SE_LOCAL_UINT_4__
#define __OPL_SE_LOCAL_UINT_4__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalUint4 {
    public:
      uint& operator[](int);
    private:
      #if 4 == 3
      uint value[4];
      #else
      uint value[4];
      #endif
    };
  }
}

#endif
