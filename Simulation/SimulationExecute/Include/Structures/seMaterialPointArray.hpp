#pragma once

#include "ClTypedMemory.hpp"
#include "seLocalMaterialPoint.hpp"

namespace OPL
{
  namespace SimExec
  {
    class IMaterialPointArray : public ClTypedMemory<LocalMaterialPoint> {
    public:
      IMaterialPointArray(int);
    };
    
    template<int n>
    class MaterialPointArray : public IMaterialPointArray {
    public:
      MaterialPointArray() : IMaterialPointArray(n) {}
    private:
      
    };
  }
}

