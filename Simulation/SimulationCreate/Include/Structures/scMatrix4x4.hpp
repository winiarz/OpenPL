#ifndef __OPL_SC_MATRIX_4X4__
#define __OPL_SC_MATRIX_4X4__

#include <string>
#include "scVariable.hpp"
#include "scTypes.hpp"

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class Matrix4x4 : public Variable {
    public:
      Matrix4x4();
      Matrix4x4(string);
      Matrix4x4 operator=(Matrix4x4);
      Matrix4x4 operator+(Matrix4x4);
      Matrix4x4 operator*(Matrix4x4);
    };
    
    Matrix4x4 operator*(Float,Matrix4x4);
  }
}

#endif
