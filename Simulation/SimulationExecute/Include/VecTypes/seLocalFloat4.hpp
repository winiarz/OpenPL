
#ifndef __OPL_SE_LOCAL_FLOAT_4__
#define __OPL_SE_LOCAL_FLOAT_4__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalFloat4 {
    public:
      float& operator[](int);
    private:
      #if 4 == 3
      float value[4];
      #else
      float value[4];
      #endif
    };
  }
}

#endif
