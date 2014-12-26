#ifndef __OPL_SE_UINT_3_ARRAY__
#define __OPL_SE_UINT_3_ARRAY__

#include "seLocalUint3.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IUint3Array : public ClArrayMemory<LocalUint3> {
    public:
      IUint3Array(int);
    };

    template<int n>
    class Uint3Array : public IUint3Array {
    public:
      Uint3Array() : IUint3Array(n)
      {
      }
    };
  }
}
#endif
