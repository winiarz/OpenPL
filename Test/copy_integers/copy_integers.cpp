
#include "copy_integers.hpp"
using namespace OPL;

SIMSTEP_IMP1( CopyIntegersSim, copy, IntArray, liczby)
{
  liczby[1] = liczby[0];
}
