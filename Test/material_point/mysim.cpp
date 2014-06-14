#include "mysim.hpp"

KERNEL_IMP1( MySim, material_point_copy, MaterialPointArray, points)
{
    points[1] = points[0];
}

KERNEL_IMP2( MySim, size_of_material_point, MaterialPointArray, points, IntArray, size)
{
  size[0] = SizeOf<MaterialPoint>();
}

KERNEL_IMP1( MySim, moving, MaterialPointArray, points)
{
    move(points[0]);
}

KERNEL_IMP2( MySim, apply_force, MaterialPointArray, points, Float3Array, forces)
{
  points[0] << forces[0] << forces[1];
  move(points[0]);
}

KERNEL_IMP2( MySim, dist, MaterialPointArray, points, FloatArray, result)
{
  result[0] = dist_sq( points[0], points[1]);
}

