#include "mysim.hpp"

SIMSTEP_IMP1( MySim, material_point_copy, MaterialPointArray, points)
{
    points[1] = points[0];
}

SIMSTEP_IMP2( MySim, size_of_material_point, MaterialPointArray, points, IntArray, size)
{
  size[0] = SizeOf<InsPr::MaterialPoint>();
}

SIMSTEP_IMP1( MySim, moving, MaterialPointArray, points)
{
    points[0].move();
}

SIMSTEP_IMP2( MySim, apply_force, MaterialPointArray, points, Float3Array, forces)
{
  points[0] << forces[0] << forces[1];
  points.move();
}

SIMSTEP_IMP2( MySim, dist, MaterialPointArray, points, FloatArray, result)
{
  result[0] = dist_sq( points[0], points[1]);
}

