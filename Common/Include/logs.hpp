#pragma once

#include "stl.hpp"
#include "LogStream.hpp"
#include <string.h>



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
#define DEBUG2 \
    if ( debugEnabled ) \
        debug(__LINE__,FILENAME)

#define DEBUG \
    if ( debugEnabled ) \
        LogStream(__LINE__,FILENAME,LOG_LEVEL_DEBUG)
    
#define ERROR \
    LogStream(__LINE__,FILENAME,LOG_LEVEL_ERROR)

