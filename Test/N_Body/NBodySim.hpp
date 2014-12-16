#pragma once

#include "Simulation.hpp"
using namespace OPL;

const unsigned int pointsNb = 64;

class NBodySim : public Simulation
{
public:
    void run();
    void setStartPositions();

    SIMSTEP_DEF1(runNBody, MaterialPointArray);

    MEMORY( MaterialPointArray, points, pointsNb);
    LocalMaterialPoint localPoints[pointsNb];
};

