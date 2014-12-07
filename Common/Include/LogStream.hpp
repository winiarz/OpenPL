#pragma once

#include "stl.hpp"
#include "ClError.hpp"

enum LogLevel 
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_ERROR
};

std::ostream& operator<<(std::ostream& sstream, LogLevel logLevel);
std::ostream& operator<<(std::ostream&, OpenClError);

class LogStream : public std::ostringstream{
public:
    LogStream(int,std::string,LogLevel);

    virtual ~LogStream();
private:
    int lineNb;
    std::string fileName;
    LogLevel logLevel; 
};

