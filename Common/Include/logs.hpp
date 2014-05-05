#ifndef __LOGS__
#define __LOGS__

#include <fstream>
#include <iostream>

std::ostream& debug(int);

const char debugFileName[] = "debug.txt";
#define DEBUG(line) debug(line)

#define DEBUG_ENABLED 1

#ifdef DEBUG_ENABLED
const bool debugEnabled=true;
#else
const bool debugEnabled=false;
#endif

#endif
