#pragma once

#include "ClArrayMemory.hpp"
#include "seLocalMatrix3x3.hpp"

namespace OPL
{
  namespace SimExec
  {
    class IMatrixFloat3x3Array : public ClArrayMemory<LocalMatrix3x3> {
    public:
      IMatrixFloat3x3Array(int);
    };
    
    template<int n>
    class MatrixFloat3x3Array : public IMatrixFloat3x3Array {
    public:
      MatrixFloat3x3Array() : IMatrixFloat3x3Array(n) {}
      
    };
  }
}

