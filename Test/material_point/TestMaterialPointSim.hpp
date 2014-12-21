
#include "Simulation.hpp"
using namespace OPL;

class MaterialPointSim : public Simulation {
public:
  MEMORY( MaterialPointArray, points, 10);
  MEMORY( IntArray, numbers, 10);
  MEMORY( Float4Array, forces, 2 );
  MEMORY( FloatArray, result, 1);
  SIMSTEP_DEF2( size_of_material_point, MaterialPointArray, IntArray);
  SIMSTEP_DEF1( material_point_copy, MaterialPointArray );
  SIMSTEP_DEF1( moving, MaterialPointArray );
  SIMSTEP_DEF2( apply_force, MaterialPointArray, Float4Array);
  SIMSTEP_DEF2( dist, MaterialPointArray, FloatArray );
};
