#ifndef __OPL_SC_NAME_GENERATOR__
#define __OPL_SC_NAME_GENERATOR__

#include <string>
#include <sstream>

using namespace std;

namespace OPL
{
  namespace SimCreate
  {
    class NameGenerator {
    public:
      static NameGenerator& getNameGenerator();
      string nextName();
    private:
      const string prefix;
      const int maxLength;
      const char firstLetter,lastLetter;
      string lastName;
      
      NameGenerator();
    };
  }
}

#endif
