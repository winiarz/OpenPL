#pragma once

#include "boost.hpp"

namespace InsPr
{
    class IVariable
    {
    public:
        virtual std::string getName() = 0;
        virtual std::string getTypeName() = 0;
    };

    class IArrayVariable : public IVariable
    {
    };

    class IGlobalArrayVariable : public IVariable
    {
    };
}

