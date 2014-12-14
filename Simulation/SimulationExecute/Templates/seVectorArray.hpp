#ifndef __OPL_SE_$TYPENAME_$LENGTH_ARRAY__
#define __OPL_SE_$TYPENAME_$LENGTH_ARRAY__

#include "seLocal$TypeName$LENGTH.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class I$TypeName$LENGTHArray : public ClArrayMemory<Local$TypeName$LENGTH> {
    public:
      I$TypeName$LENGTHArray(int);
    };

    template<int n>
    class $TypeName$LENGTHArray : public I$TypeName$LENGTHArray {
    public:
      $TypeName$LENGTHArray() : I$TypeName$LENGTHArray(n)
      {
      }
    };
  }
}
#endif
