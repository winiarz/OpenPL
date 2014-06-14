#pragma once

#include <string>
#include "scArray.hpp"
#include "scMatrix3x3.hpp"
#include "scInt.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class MatrixFloat3x3Array : public Array {
    public:
      MatrixFloat3x3Array(string);
      static string getTypeName();
      MatrixFloat3x3 operator[](Int n);
    };
  }
}

