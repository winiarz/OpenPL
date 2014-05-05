#ifndef __OPL_SE_MATRIX_3X3_ARRAY__
#define __OPL_SE_MATRIX_3X3_ARRAY__

#include "ClTypedMemory.hpp"
#include "seLocalMatrix3x3.hpp"

namespace OPL
{
  namespace SimExec
  {
    class IMatrix3x3Array : public ClTypedMemory<LocalMatrix3x3> {
    public:
      IMatrix3x3Array(int);
    };
    
    template<int n>
    class Matrix3x3Array : public IMatrix3x3Array {
    public:
      Matrix3x3Array() : IMatrix3x3Array(n) {}
      
    };
  }
}

#endif
