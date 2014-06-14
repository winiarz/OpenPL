#pragma once

#include <string>
#include "scVariable.hpp"
#include "scTypes.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class MatrixFloat3x3 : public Variable {
    public:
      MatrixFloat3x3();
      MatrixFloat3x3(string);
      MatrixFloat3x3 operator=(MatrixFloat3x3);
      MatrixFloat3x3 operator+(MatrixFloat3x3);
      MatrixFloat3x3 operator*(MatrixFloat3x3);
    };
    
    MatrixFloat3x3 operator*(Float,MatrixFloat3x3);
  }
}

