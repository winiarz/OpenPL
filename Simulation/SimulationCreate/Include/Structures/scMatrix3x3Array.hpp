#ifndef __OPL_SC_MATRIX_3X3_ARRAY__
#define __OPL_SC_MATRIX_3X3_ARRAY__

#include <string>
#include "scArray.hpp"
#include "scMatrix3x3.hpp"
#include "scInt.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class Matrix3x3Array : public Array {
    public:
      Matrix3x3Array(string);
      static string getTypeName();
      Matrix3x3 operator[](Int n);
    };
  }
}

#endif