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
    
    class Matrix4x4Array : public Array {
    public:
      Matrix4x4Array(string);
      static string getTypeName();
      Matrix4x4 operator[](Int n);
    private:
      
    };
  }
}

