#ifndef __OPL_SE_FLOAT_ARRAY__
#define __OPL_SE_FLOAT_ARRAY__

#include "ClPlatform.hpp"
#include "ClArrayMemory.hpp"
#include "seArray.hpp"

namespace OPL

{
  namespace SimExec
  {
    using namespace std;

    class IFloatArray : public ClArrayMemory<float> {
    public:
      IFloatArray(int);
    };

    template<int n>
    class FloatArray : public IFloatArray {
    public:
      FloatArray() : IFloatArray(n)
      {
      }
    };
  }
}
#endif
