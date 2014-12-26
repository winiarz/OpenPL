#ifndef __OPL_SE_INT_4_ARRAY__
#define __OPL_SE_INT_4_ARRAY__

#include "seLocalInt4.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IInt4Array : public ClArrayMemory<LocalInt4> {
    public:
      IInt4Array(int);
    };

    template<int n>
    class Int4Array : public IInt4Array {
    public:
      Int4Array() : IInt4Array(n)
      {
      }
    };
  }
}
#endif
