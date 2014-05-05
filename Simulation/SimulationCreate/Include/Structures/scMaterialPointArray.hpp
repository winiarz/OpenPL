#ifndef __OPL_SC_MATERIAL_POINT_ARRAY__
#define __OPL_SC_MATERIAL_POINT_ARRAY__

#include <sstream>
#include "scArray.hpp"
#include "scMaterialPoint.hpp"

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class MaterialPointArray : public Array {
    public:
      MaterialPointArray(string);
      static string getTypeName();
      
      MaterialPoint operator[](int);
    };
  }
}

#endif
