
__kernel void addition(__global int* a,__global int* b,__global int* c,__global int* size)
{
  int i = get_global_id(0);
  int ker_size = get_global_size(0);
  
  for( ;i<size[0];i+=ker_size)
  {
    c[i] = a[i] + b[i];
  }
}
