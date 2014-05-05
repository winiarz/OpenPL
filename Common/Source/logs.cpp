#include "logs.hpp"
#include "NullStream.hpp"

std::ostream& debug(int lineNb)
{
    if(debugEnabled)
    {
      static std::ofstream debugFile("debug.txt",std::ofstream::out);
      
      debugFile << lineNb << " ";
    
      return debugFile;
    }
    else
    {
      static NullStream nullStream;
      return nullStream;
    }
}
