#include "material_point.cl"

void material_point_move(__global struct MaterialPoint* p,int first,int last,int step)
{
  for(int i=first; i<last; i += step)
  {
    p[i].speed += p[i].force / p[i].mass;
    p[i].position = p[i].position + p[i].speed;
  }
}

void material_point_apply_force(__global struct MaterialPoint* points, int size, float4 force)
{
    for(int i=0; i<size; i++)
    {
        points[i].force = force;
    }
}
