#ifndef __OPL_SE_FLOAT_4_ARRAY__
#define __OPL_SE_FLOAT_4_ARRAY__

#include "seLocalFloat4.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IFloat4Array : public ClArrayMemory<LocalFloat4> {
    public:
      IFloat4Array(int);
    };

    template<int n>
    class Float4Array : public IFloat4Array {
    public:
      Float4Array() : IFloat4Array(n)
      {
      }
    };
  }
}
#endif
