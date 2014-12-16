#include "material_point.cl"

void material_point_apply_forces_of_gravity(__global struct MaterialPoint* points, uint size, float gravityConstant)
{
    float epsilon = 1.0f;
    for (uint i=get_global_id(0); i<size; i+=get_global_size(0))
    {
        float4 forcesSum= (float4)0;

        for (uint j=0; j<size; j++) 
        {
            float4 position_delta = points[i].position - points[j].position;
            float4 position_delta_sq = position_delta*position_delta; 
            float dist_sq = position_delta_sq.x + position_delta_sq.y + position_delta_sq.z + epsilon;
            float inverse_dist = rsqrt(dist_sq);
            forcesSum += inverse_dist*inverse_dist*inverse_dist * points[j].mass * position_delta;
        }

        points[i].force += gravityConstant * forcesSum;
    }
}

