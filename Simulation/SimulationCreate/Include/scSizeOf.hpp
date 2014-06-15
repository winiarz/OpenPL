#pragma once

#include "scInt.hpp"
#include "scVariable.hpp"
#include "Int.hpp"

namespace OPL
{
  namespace SimCreate
  {
    Int SizeOf(Variable&);

    template<typename T>
    InsPr::Int SizeOf()
    {
      ostringstream variableName;
      variableName << "sizeof (" << T("").getTypeName() << " ) ";
      return InsPr::Int( variableName.str());
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

