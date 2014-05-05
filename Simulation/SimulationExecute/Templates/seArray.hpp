#ifndef __OPL_SE_$TYPENAME_ARRAY__
#define __OPL_SE_$TYPENAME_ARRAY__

#include "ClPlatform.hpp"
#include "ClTypedMemory.hpp"
#include "seArray.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class I$TypeNameArray : public ClTypedMemory<$typename> {
    public:
      I$TypeNameArray(int);
    };

    template<int n>
    class $TypeNameArray : public I$TypeNameArray {
    public:
      $TypeNameArray() : I$TypeNameArray(n)
      {
      }
    };
  }
}
#endif
