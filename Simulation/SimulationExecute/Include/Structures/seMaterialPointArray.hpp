#ifndef __OPL_SE_MATERIAL_POINT_ARRAY__
#define __OPL_SE_MATERIAL_POINT_ARRAY__

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

#endif
