
#include "Simulation.hpp"
using namespace OPL;

class CopyIntegersSim : public Simulation {
public:
  SIMSTEP_DEF1( copy, IntArray );
  MEMORY( IntArray, liczby, 10);
};
