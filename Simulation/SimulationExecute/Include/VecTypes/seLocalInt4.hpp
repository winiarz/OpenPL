
#ifndef __OPL_SE_LOCAL_INT_4__
#define __OPL_SE_LOCAL_INT_4__

#include "seAdditionalTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalInt4 {
    public:
      int& operator[](int);
    private:
      #if 4 == 3
      int value[4];
      #else
      int value[4];
      #endif
    };
  }
}

#endif
