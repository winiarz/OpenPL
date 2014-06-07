#pragma once

#include "IType.hpp"

namespace InsPr
{
    class Type : public IType
    {
    public:
        Type(std::string);
        virtual std::string getTypeName();
    private:
        std::string typeName;
    };
}

