#pragma once

#include <string>
#include "scArray.hpp"
#include "scMatrix4x4.hpp"
#include "scInt.hpp"

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    
    class MatrixFloat4x4Array : public Array {
    public:
      MatrixFloat4x4Array(string);
      static string getTypeName();
      MatrixFloat4x4 operator[](Int n);
    private:
      
    };
  }
}

