#include "seLocalMaterialPoint.hpp"
using namespace OPL::SimExec;

bool LocalMaterialPoint::operator==(LocalMaterialPoint& rValue)
{
  return position[0] == rValue.position[0] && position[1] == rValue.position[1] && position[2] == rValue.position[2] && 
	 speed[0] == rValue.speed[0] && speed[1] == rValue.speed[1] && speed[2] == rValue.speed[2] && 
	 force[0] == rValue.force[0] && force[1] == rValue.force[1] && force[2] == rValue.force[2] && 
	 mass == rValue.mass;
}
