
#include "TestSimpleAritmeticsSim.hpp"

SIMSTEP_IMP1( SimpleAritmeticsSim, add, IntArray, liczby)
{
  liczby[2] = liczby[1] + liczby[0];
}

SIMSTEP_IMP1( SimpleAritmeticsSim, sub, IntArray, liczby) 
{
  liczby[2] = liczby[1] - liczby[0];
}

SIMSTEP_IMP1( SimpleAritmeticsSim, mult, IntArray, liczby)
{
  liczby[2] = liczby[1] * liczby[0];
}

SIMSTEP_IMP1( SimpleAritmeticsSim, div, IntArray, liczby)
{
  liczby[2] = liczby[1] / liczby[0];
}

SIMSTEP_IMP1( SimpleAritmeticsSim, mod, IntArray, liczby)
{
  liczby[2] = liczby[1] % liczby[0];
}
