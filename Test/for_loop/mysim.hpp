
#include "Simulation.hpp"
using namespace OPL;

class ForLoopSim : public Simulation {
public:
  MEMORY( IntArray, numbers, 3);
  SIMSTEP_DEF1( power, IntArray );
};
