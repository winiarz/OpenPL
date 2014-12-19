
#include "Simulation.hpp"
using namespace InsPr;

class SimpleAritmeticsSim : public Simulation {
public:
  SIMSTEP_DEF1( add, IntArray );
  SIMSTEP_DEF1( sub, IntArray );
  SIMSTEP_DEF1( mult, IntArray );
  SIMSTEP_DEF1( div, IntArray );
  SIMSTEP_DEF1( mod, IntArray );
  MEMORY( IntArray, liczby, 10);
};
