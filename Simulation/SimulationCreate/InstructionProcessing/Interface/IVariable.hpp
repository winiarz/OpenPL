#pragma once

#include "boost.hpp"
#include "IType.hpp"

namespace InsPr
{
    class IVariable
    {
    public:
        virtual boost::shared_ptr<IType> getType() = 0;
        virtual std::string getName() = 0;
    };
}

