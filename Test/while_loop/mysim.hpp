
#include "Simulation.hpp"
using namespace OPL;

class MySim : public Simulation {
public:
  MEMORY( IntArray, numbers, 3);
  KERNEL_DEF1( while_test, IntArray );
};
