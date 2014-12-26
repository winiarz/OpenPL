#ifndef __OPL_SE_INT_3_ARRAY__
#define __OPL_SE_INT_3_ARRAY__

#include "seLocalInt3.hpp"
#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"
#include "seAdditionalTypes.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IInt3Array : public ClArrayMemory<LocalInt3> {
    public:
      IInt3Array(int);
    };

    template<int n>
    class Int3Array : public IInt3Array {
    public:
      Int3Array() : IInt3Array(n)
      {
      }
    };
  }
}
#endif
