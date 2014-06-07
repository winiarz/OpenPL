#pragma once

#include "stl.hpp"

namespace InsPr
{
    class IInstruction 
    {
    public:
        virtual uint getAlternativesCount() = 0;
        virtual std::vector<std::string> getAllAlternatives() = 0;
    };
}

