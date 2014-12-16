#include "NBodySim.hpp"

const float G=0.001;

void NBodySim::run()
{
    setStartPositions();
    points.copyIn(localPoints,0,pointsNb);

    runNBody(points);

    points.copyOut(localPoints,0,pointsNb);
}

void NBodySim::setStartPositions()
{
    for (uint i=0;i<pointsNb;i++) 
    {
        float alpha = 0.01f * float(i);
        localPoints[i].position[0] = cos(alpha) * 5.0f;
        localPoints[i].position[1] = sin(alpha) * 5.0f;
        localPoints[i].position[2] = 0.0f;

        localPoints[i].speed[0] = localPoints[i].speed[1] = localPoints[i].speed[2] = 0.0f;
        localPoints[i].mass = 10.0f;
    }
}

SIMSTEP_IMP1(NBodySim, runNBody,
             MaterialPointArray, points)
{
    points.clearForce();
    points.applyForcesOfGravity(G);
    points.move();
}

