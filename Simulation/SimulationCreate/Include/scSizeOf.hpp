#pragma once

#include "Int.hpp"

namespace OPL
{
  namespace SimCreate
  {
    template<typename T>
    InsPr::Int SizeOf()
    {
      ostringstream variableName;
      variableName << "sizeof (" << T("").getTypeName() << " ) ";
      return InsPr::Int( variableName.str());
    }
  }
}

