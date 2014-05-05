
#ifndef __OPL_SC_SIMULATION_CREATE__
#define __OPL_SC_SIMULATION_CREATE__
#pragma once

#include "scVariable.hpp"
#include "scTypes.hpp"
#include "scStructures.hpp"
#include "scArray.hpp"
#include "scSizeOf.hpp"

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
      static Float det(Matrix4x4);
      static Float det(Matrix3x3);
      static Matrix3x3 invert(Matrix3x3);
      static void FOR_PARALLEL( Int, Int, Int );
      static void IF_INSTRUCTION( Bool );
      static void WHILE_INSTRUCTION( Bool );
      static void ELSE_INSTRUCTION();
      static void print_opening_brace();
      static void print_closing_brace();
    };
  }
}

#endif
