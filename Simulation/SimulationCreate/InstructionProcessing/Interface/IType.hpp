#pragma once

#include "stl.hpp"

namespace InsPr
{
    class IType
    {
    public:
        virtual std::string getTypeName() = 0;
    };
}

