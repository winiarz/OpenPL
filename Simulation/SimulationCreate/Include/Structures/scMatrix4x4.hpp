#pragma once

#include <string>
#include "scVariable.hpp"
#include "scTypes.hpp"

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class MatrixFloat4x4 : public Variable {
    public:
      MatrixFloat4x4();
      MatrixFloat4x4(string);
      MatrixFloat4x4 operator=(MatrixFloat4x4);
      MatrixFloat4x4 operator+(MatrixFloat4x4);
      MatrixFloat4x4 operator*(MatrixFloat4x4);
    };
    
    MatrixFloat4x4 operator*(Float,MatrixFloat4x4);
  }
}

