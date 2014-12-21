#pragma once

#include "boost.hpp"
#include "stl.hpp"

namespace OPL
{
namespace InsPr
{
    class IKernel
    {
    public:
        virtual uint getAlternativesCount() = 0;
        virtual std::string getAlternative(uint) = 0;
    };
}
}

