#include "LogStream.hpp"
#include "logs.hpp"

LogStream::LogStream(int p_lineNb, std::string p_fileName, LogLevel p_logLevel) :
    lineNb(p_lineNb),
    fileName(p_fileName),
    logLevel(p_logLevel)
{}

std::ostream& operator<<(std::ostream& sstream, LogLevel logLevel)
{
    switch (logLevel) 
    {
    case LOG_LEVEL_ERROR:
        sstream << "ERR";
        break;
    case LOG_LEVEL_DEBUG:
        sstream << "DEB";
        break;
    }
    return sstream;
}

LogStream::~LogStream()
{
    static std::ofstream debugFile(debugFileName,std::ofstream::out);

    debugFile << fileName << ":" << lineNb << " " << this->str() << std::endl;
}

