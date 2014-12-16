#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "NBodySim.hpp"

class NBodyTS : public ::testing::Test {
protected:
    NBodySim sim;
};

TEST_F(NBodyTS, nbody_with_default_gravity_constant)
{
    sim.run();

    uint nb = pointsNb-1;
    cout << sim.localPoints[nb].position[0] << ", " 
         << sim.localPoints[nb].position[1] << ", " 
         << sim.localPoints[nb].position[2] << endl;
    cout << sim.localPoints[nb].speed[0] << ", " 
         << sim.localPoints[nb].speed[1] << ", "
         << sim.localPoints[nb].speed[2] << endl;
}

