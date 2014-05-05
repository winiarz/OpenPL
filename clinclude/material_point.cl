
struct MaterialPoint {

float4 position;
float4 speed;
float4 force;
float mass;
float nothing[3]; 

};

float material_point_dist_sq(struct MaterialPoint p1,struct MaterialPoint p2)
{
    float4 sub = p1.position - p2.position;
    sub = sub * sub;
    return sub.x + sub.y + sub.z;
}
