#pragma once

#include "scSizeOf.hpp"
#include "Float.hpp"
#include "MatrixVariable.hpp"
#include "MaterialPoint.hpp"
#include "IntGlobalArray.hpp"
#include "MaterialPointArrayGlobal.hpp"

namespace OPL
{
  namespace SimCreate
  {
    class Simulation {
    public:
      static InsPr::MatrixFloat3x3 invert(InsPr::MatrixFloat3x3);
    };
  }
}

