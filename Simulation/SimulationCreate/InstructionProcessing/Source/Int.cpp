#include "Int.hpp"

namespace InsPr
{

Int operator%(Int first, Int second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " % " << second.getName();
    return Int( sstream.str());
}

}

