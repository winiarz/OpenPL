#pragma once

#include "boost.hpp"
#include "stl.hpp"

namespace InsPr
{
    class IKernel
    {
    public:
        virtual uint getAlternativesCount() = 0;
        virtual std::string getAlternative(uint) = 0;
    };
}

