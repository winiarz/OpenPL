
void material_point_move(__global struct MaterialPoint* p,int first,int last,int step)
{
  for(int i=first; i<last; i += step)
  {
    p[i].speed += p[i].force;
    p[i].position = p[i].position + p[i].speed;
  }
}
