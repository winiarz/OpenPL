#ifndef __OPL_SE_FLOAT_3_ARRAY__
#define __OPL_SE_FLOAT_3_ARRAY__

#include "seLocalFloat3.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IFloat3Array : public ClArrayMemory<LocalFloat3> {
    public:
      IFloat3Array(int);
    };

    template<int n>
    class Float3Array : public IFloat3Array {
    public:
      Float3Array() : IFloat3Array(n)
      {
      }
    };
  }
}
#endif
