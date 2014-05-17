#include "logs.hpp"
#include "NullStream.hpp"

std::ostream& debug(int lineNb, std::string filename)
{
    static std::ofstream debugFile(debugFileName,std::ofstream::out);
      
    debugFile << std::endl << filename << ":" << lineNb << " ";
    
    return debugFile;
}
