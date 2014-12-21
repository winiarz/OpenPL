#pragma once
#include "Simulation.hpp"
using namespace OPL;

const unsigned int pointsNb = 1 << 14;

class ConstantForceSim : public Simulation
{
public:
    void setUp();
    void run();
    void getResults();

    SIMSTEP_DEF2( applyConstantForceAndMove, MaterialPointArray, Float4Array );

    MEMORY( MaterialPointArray, points, pointsNb);
    MEMORY( Float4Array, force, 1 );

    LocalMaterialPoint localPoints[pointsNb];
};

