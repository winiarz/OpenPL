#pragma once

#include "ClArrayMemoryWithSize.hpp"
#include "seLocalMaterialPoint.hpp"

namespace OPL
{
  namespace SimExec
  {
    class IMaterialPointArray : public ClArrayMemoryWithSize<LocalMaterialPoint> {
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

