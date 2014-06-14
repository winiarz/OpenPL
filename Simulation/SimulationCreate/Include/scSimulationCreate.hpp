#pragma once

#include "scVariable.hpp"
#include "scTypes.hpp"
#include "scStructures.hpp"
#include "scArray.hpp"
#include "scSizeOf.hpp"
#include "Float.hpp"
#include "MatrixVariable.hpp"

namespace OPL
{
  namespace SimCreate
  {
    using namespace std;
    using namespace OPL::SimCreate;
    
    class Simulation {
    public:
      static void move(MaterialPoint);
      static void move(MaterialPointArray&,int,int);
      static Float dist_sq(MaterialPoint, MaterialPoint);
      static InsPr::Float det(InsPr::MatrixFloat4x4);
      static InsPr::Float det(InsPr::MatrixFloat3x3);
      static InsPr::MatrixFloat3x3 invert(InsPr::MatrixFloat3x3);
      static void print_opening_brace();
      static void print_closing_brace();
    };
  }
}

