#pragma once
#include "seTypes.hpp"

namespace OPL
{
  namespace SimExec
  {
    class LocalMaterialPoint {
    public:
    LocalFloat3 position;
    LocalFloat3 speed;
    LocalFloat3 force;
    LocalFloat mass;
    LocalFloat nothing[3];
    bool operator==( LocalMaterialPoint& );
    };
  }
}

