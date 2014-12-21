#pragma once

#include "stl.hpp"

namespace OPL
{
namespace InsPr
{
    class IInstruction 
    {
    public:
        virtual uint getAlternativesCount() = 0;
        virtual std::string getAlternative(uint) = 0;
    };
}
}

