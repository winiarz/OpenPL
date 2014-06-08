#pragma once

#include "IType.hpp"
#include "IVariable.hpp"

namespace InsPr
{
    template<class T>
    class ArrayType : public IType
    {
        static_assert(std::is_base_of<IType, T>::value, "T not derived from IType");

    public:
        ArrayType(uint p_arraySize)
        {}

        virtual std::string getTypeName()
        {
            std::ostringstream sstream;
            sstream << T().getTypeName() << "* ";
            return sstream.str();
        }
    };

    template<class T>
    class GlobalArrayType : public IGlobalArrayType
    {
    public:
        GlobalArrayType()
        {}

        virtual std::string getTypeName()
        {
            std::ostringstream sstream;
            sstream << "__global " << T().getTypeName() << "* ";
            return sstream.str();
        }
    };
}

