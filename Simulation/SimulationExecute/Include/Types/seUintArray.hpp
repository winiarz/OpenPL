#ifndef __OPL_SE_UINT_ARRAY__
#define __OPL_SE_UINT_ARRAY__

#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IUintArray : public ClArrayMemory<uint> {
    public:
      IUintArray(int);
    };

    template<int n>
    class UintArray : public IUintArray {
    public:
      UintArray() : IUintArray(n)
      {
      }
    };
  }
}
#endif
