#pragma once

#include "ClTypedMemory.hpp"
#include "seLocalMatrix4x4.hpp"

namespace OPL
{
  namespace SimExec
  {
    class IMatrix4x4Array : public ClTypedMemory<LocalMatrix4x4> {
    public:
      IMatrix4x4Array(int);
    };
    
    template<int n>
    class Matrix4x4Array : public IMatrix4x4Array {
    public:
      Matrix4x4Array() : IMatrix4x4Array(n) {}
      
    };
  }
}

