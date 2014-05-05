#ifndef __OPL_SC_SIZE_OF__
#define __OPL_SC_SIZE_OF__

#include "scInt.hpp"
#include "scVariable.hpp"

namespace OPL
{
  namespace SimCreate
  {
    Int SizeOf(Variable&);
    
    template<typename T>
    Int SizeOf()
    {
      ostringstream variableName;
      variableName << "sizeof (" << T::getTypeName() << " ) ";
      return Int( variableName.str());
    }
    
    template<typename T>
    Int OffsetOf(T example,string fieldName)
    {
      ostringstream variableName;
      variableName << "(int)(&" << example.getName() << "." << fieldName << ") - (int)(&example[0])";
      return Int( variableName.str());
    }
  }
}

#endif
