#include "Int.hpp"

namespace OPL
{
namespace InsPr
{

Int operator%(Int first, Int second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " % " << second.getName();
    return Int( sstream.str());
}

Int operator+( Int left, Int right )
{
    std::ostringstream sstream;
    sstream << left.getName() << " + " << right.getName();
    return Int( sstream.str());
}

Int operator/( Int left, Int right )
{
    std::ostringstream sstream;
    sstream << left.getName() << " / " << right.getName();
    return Int( sstream.str());
}

}
}

