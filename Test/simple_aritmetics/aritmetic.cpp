
#include "aritmetic.hpp"

SIMSTEP_IMP1( MySim, add, IntArray, liczby)
{
  liczby[2] = liczby[1] + liczby[0];
}

SIMSTEP_IMP1( MySim, sub, IntArray, liczby) 
{
  liczby[2] = liczby[1] - liczby[0];
}

SIMSTEP_IMP1( MySim, mult, IntArray, liczby)
{
  liczby[2] = liczby[1] * liczby[0];
}

SIMSTEP_IMP1( MySim, div, IntArray, liczby)
{
  liczby[2] = liczby[1] / liczby[0];
}

SIMSTEP_IMP1( MySim, mod, IntArray, liczby)
{
  liczby[2] = liczby[1] % liczby[0];
}
