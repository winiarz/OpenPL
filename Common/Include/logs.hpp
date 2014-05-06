#ifndef __LOGS__
#define __LOGS__

#include <string>
#include <string.h>
#include <fstream>
#include <iostream>

#define DEBUG_ENABLED 1

#ifdef DEBUG_ENABLED
const bool debugEnabled=true;
#else
const bool debugEnabled=false;
#endif

std::ostream& debug(int,std::string);
std::ostream& error(int,std::string);

#define FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

const char debugFileName[] = "debug.txt";
#define DEBUG \
    if ( debugEnabled ) \
        debug(__LINE__,FILENAME)
    
#define ERROR \
    debug(__LINE__,FILENAME)

#endif

