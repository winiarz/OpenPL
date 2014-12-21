
#include "Simulation.hpp"
using namespace OPL;

class DeclareMemorySim : public Simulation {
public:
  SIMSTEP_DEF0( empty );
  MEMORY( IntArray, numbers, 10);
};
