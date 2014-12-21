#include "Uint.hpp"

namespace OPL
{
namespace InsPr
{

Uint operator%(Uint first, Uint second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " % " << second.getName();
    return Uint( sstream.str());
}

Uint operator+( Uint left, Uint right )
{
    std::ostringstream sstream;
    sstream << left.getName() << " + " << right.getName();
    return Uint( sstream.str());
}

Uint operator/( Uint left, Uint right )
{
    std::ostringstream sstream;
    sstream << left.getName() << " / " << right.getName();
    return Uint( sstream.str());
}

}
}

