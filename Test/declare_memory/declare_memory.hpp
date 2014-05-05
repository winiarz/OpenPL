
#include "Simulation.hpp"
using namespace OPL;

class MySim : public Simulation {
public:
  KERNEL_DEF0( empty );
  MEMORY( IntArray, liczby, 10);
};
