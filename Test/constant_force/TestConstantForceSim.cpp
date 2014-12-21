#include "TestConstantForceSim.hpp"

void ConstantForceSim::setUp()
{
    for (unsigned int i=0; i<pointsNb; i++) 
    {
        localPoints[i].position[0] = localPoints[i].position[1] = localPoints[i].position[2] = 0.0f;
        localPoints[i].speed[0]    = localPoints[i].speed[1]    = localPoints[i].speed[2] = 0.0f;
        localPoints[i].force[0]    = localPoints[i].force[1]    = localPoints[i].force[2] = 0.0f;
        localPoints[i].mass = float(5 + i%5);
    }
    points.copyIn(localPoints, 0, pointsNb);

    LocalFloat4 localForce;
    localForce[0] = 0.0f;
    localForce[1] = -1.0f;
    localForce[2] = 0.0f;
    force.copyIn(&localForce, 0, 1);
}

void ConstantForceSim::run()
{
    setUp();

    for (int i=0;i<5;i++) 
    {
        applyConstantForceAndMove(points, force);
    }

    getResults();
}

void ConstantForceSim::getResults()
{
    points.copyOut(localPoints, 0, pointsNb);
}

SIMSTEP_IMP2( ConstantForceSim, applyConstantForceAndMove,
              MaterialPointArray, points,
              Float4Array, force)
{
    points.setForce(force[0]);
    points.move();
}
