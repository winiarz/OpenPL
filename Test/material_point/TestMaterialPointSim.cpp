#include "TestMaterialPointSim.hpp"

SIMSTEP_IMP1( MaterialPointSim, material_point_copy, MaterialPointArray, points)
{
    points[1] = points[0];
}

SIMSTEP_IMP2( MaterialPointSim, size_of_material_point, MaterialPointArray, points, IntArray, size)
{
  size[0] = SizeOf<InsPr::MaterialPoint>();
}

SIMSTEP_IMP1( MaterialPointSim, moving, MaterialPointArray, points)
{
    points[0].move();
}

SIMSTEP_IMP2( MaterialPointSim, apply_force, MaterialPointArray, points, Float4Array, forces)
{
  points[0].setForce(forces[0]);
  points.move();
}

SIMSTEP_IMP2( MaterialPointSim, dist, MaterialPointArray, points, FloatArray, result)
{
  result[0] = points[0].dist_sq(points[1]);
}

