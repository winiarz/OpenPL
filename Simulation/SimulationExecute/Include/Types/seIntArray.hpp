#ifndef __OPL_SE_INT_ARRAY__
#define __OPL_SE_INT_ARRAY__

#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IIntArray : public ClArrayMemory<int> {
    public:
      IIntArray(int);
    };

    template<int n>
    class IntArray : public IIntArray {
    public:
      IntArray() : IIntArray(n)
      {
      }
    };
  }
}
#endif
