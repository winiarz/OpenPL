
#ifndef __OPL_SE_LOCAL_FLOAT_3__
#define __OPL_SE_LOCAL_FLOAT_3__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalFloat3 {
    public:
      float& operator[](int);
    private:
      #if 3 == 3
      float value[4];
      #else
      float value[3];
      #endif
    };
  }
}

#endif
