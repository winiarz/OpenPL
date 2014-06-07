#pragma once

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

