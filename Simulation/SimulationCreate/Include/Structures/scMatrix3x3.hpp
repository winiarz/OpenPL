#ifndef __OPL_SC_MATRIX_3X3__
#define __OPL_SC_MATRIX_3X3__

#include <string>
#include "scVariable.hpp"
#include "scTypes.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class Matrix3x3 : public Variable {
    public:
      Matrix3x3();
      Matrix3x3(string);
      Matrix3x3 operator=(Matrix3x3);
      Matrix3x3 operator+(Matrix3x3);
      Matrix3x3 operator*(Matrix3x3);
    };
    
    Matrix3x3 operator*(Float,Matrix3x3);
  }
}

#endif
