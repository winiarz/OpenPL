#include "Type.hpp"

namespace InsPr
{
Type::Type(std::string p_typeName) :
    typeName(p_typeName)
{
}

std::string Type::getTypeName()
{
    return typeName;
}

}

