
#include "Simulation.hpp"

class MySim : public Simulation {
public:
  KERNEL_DEF1( add, IntArray );
  KERNEL_DEF1( sub, IntArray );
  KERNEL_DEF1( mult, IntArray );
  KERNEL_DEF1( div, IntArray );
  KERNEL_DEF1( mod, IntArray );
  MEMORY( IntArray, liczby, 10);
};
