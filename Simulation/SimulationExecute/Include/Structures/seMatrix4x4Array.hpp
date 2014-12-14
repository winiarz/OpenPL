#pragma once

#include "ClArrayMemory.hpp"
#include "seLocalMatrix4x4.hpp"

namespace OPL
{
  namespace SimExec
  {
    class IMatrixFloat4x4Array : public ClArrayMemory<LocalMatrix4x4> {
    public:
      IMatrixFloat4x4Array(int);
    };
    
    template<int n>
    class MatrixFloat4x4Array : public IMatrixFloat4x4Array {
    public:
      MatrixFloat4x4Array() : IMatrixFloat4x4Array(n) {}
      
    };
  }
}

