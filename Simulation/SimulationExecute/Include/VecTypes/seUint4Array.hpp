#ifndef __OPL_SE_UINT_4_ARRAY__
#define __OPL_SE_UINT_4_ARRAY__

#include "seLocalUint4.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IUint4Array : public ClArrayMemory<LocalUint4> {
    public:
      IUint4Array(int);
    };

    template<int n>
    class Uint4Array : public IUint4Array {
    public:
      Uint4Array() : IUint4Array(n)
      {
      }
    };
  }
}
#endif
