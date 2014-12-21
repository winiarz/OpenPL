
#include "Simulation.hpp"
using namespace OPL;

class IfCommandTestSim : public Simulation {
public:
  MEMORY( IntArray, numbers, 3);
  SIMSTEP_DEF1( if_test, IntArray );
  SIMSTEP_DEF1( if_else_test, IntArray );
};
