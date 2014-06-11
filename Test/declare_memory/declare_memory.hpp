
#include "Simulation.hpp"
using namespace OPL;

class MySim : public Simulation {
public:
  SIMSTEP_DEF0( empty );
  MEMORY( IntArray, numbers, 10);
};
