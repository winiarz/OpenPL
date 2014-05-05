#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "mysim.hpp"

class MaterialPointTS : public ::testing::Test {
protected:
  MySim sim;
};

TEST_F(MaterialPointTS, size_of_material_point)
{
  int size[1] = {0};
  sim.size_of_material_point( sim.points, sim.numbers );
  sim.numbers.copyOut( size, 0, 1 );
  ASSERT_EQ( sizeof(LocalMaterialPoint), size[0] );
}

TEST_F(MaterialPointTS, copy_of_material_point)
{
  LocalMaterialPoint loc_points[2];
  sim.points.copyIn ( loc_points, 0, 2 );
  sim.material_point_copy(sim.points);
  sim.points.copyOut( loc_points, 0, 2 );
  ASSERT_TRUE( loc_points[0] == loc_points[1] );
}

TEST_F(MaterialPointTS, not_moving_point)
{
  LocalMaterialPoint loc_points[1];
  for(int i=0;i<3;i++)
    loc_points[0].position[i] = loc_points[0].speed[i] = loc_points[0].force[i] = 0;
  
  sim.points.copyIn( loc_points, 0, 1 );
  sim.moving( sim.points );
  sim.points.copyOut( loc_points, 0, 1 );
  for(int i=0;i<3;i++)
  {
    ASSERT_EQ( loc_points[0].position[i], 0 );
    ASSERT_EQ( loc_points[0].speed[i], 0 );
    ASSERT_EQ( loc_points[0].force[i], 0 );
  }
}

TEST_F(MaterialPointTS, escaping_point )
{
  LocalMaterialPoint loc_points[1];
  for(int i=0;i<3;i++)
    loc_points[0].position[i] = loc_points[0].speed[i] = loc_points[0].force[i] = 0;
  
  loc_points[0].speed[0] = 1.0f;
  
  sim.points.copyIn( loc_points, 0, 1 );
  for(int i=0;i<100;i++)
    sim.moving( sim.points );
  sim.points.copyOut( loc_points, 0, 1 );
  for(int i=1;i<3;i++)
  {
    ASSERT_EQ( loc_points[0].position[i], 0 );
    ASSERT_EQ( loc_points[0].speed[i], 0 );
    ASSERT_EQ( loc_points[0].force[i], 0 );
  }
  
  ASSERT_TRUE( loc_points[0].position[0] > 10.0 );
}

TEST_F(MaterialPointTS, apply_froces )
{
  LocalMaterialPoint loc_point;
  LocalFloat3 forces[2];
  for(int i=0;i<3;i++)
  {
    loc_point.position[i] = 0;
    loc_point.speed[i] = 0;
    loc_point.force[i] = 0;
    forces[0][i] = 0;
    forces[1][i] = 0;
  }
  forces[0][0] = 1;
  sim.points.copyIn(&loc_point,0,1);
  sim.forces.copyIn(forces,0,2);
  sim.apply_force(sim.points, sim.forces );
  sim.points.copyOut(&loc_point,0,1);
  ASSERT_TRUE( loc_point.position[0] > 0.5f );
}

TEST_F(MaterialPointTS, distance )
{
  LocalMaterialPoint loc_points[2];    
  for(int i=0;i<3;i++)
    for(int j=0;j<2;j++)
    {
      loc_points[j].position[i] = 0;
      loc_points[j].speed[i] = 0;
      loc_points[j].force[i] = 0;
    }
 loc_points[0].position[0] = 1;
 loc_points[1].position[1] = 1;
 sim.points.copyIn( loc_points, 0, 2);
 sim.dist( sim.points, sim.result );
 float dist_sq;
 sim.result.copyOut(&dist_sq,0,1);
 ASSERT_FLOAT_EQ( dist_sq, 2.0 );
}
