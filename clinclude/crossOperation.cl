
float3 floatCrossProduct(float3 vec1, float3 vec2)
{
  float3 result;
  result.x = vec1.y*vec2.z - vec1.z*vec2.y;
  result.y = vec1.z*vec2.x - vec1.x*vec2.z;
  result.z = vec1.x*vec2.y - vec1.y*vec2.x;
  return result;
}

