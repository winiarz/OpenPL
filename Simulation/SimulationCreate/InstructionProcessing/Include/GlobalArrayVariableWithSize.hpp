#pragma once

#include "Variable.hpp"
#include "Uint.hpp"

namespace InsPr
{
    template<typename T>
    class GlobalArrayVariableWithSize : public IGlobalArrayVariable
    {
    public:
        static_assert(std::is_base_of<IVariable, T>(), "T must be IVariable!");

        GlobalArrayVariableWithSize() :
            array(),
            size()
        {}


        GlobalArrayVariableWithSize(std::string p_name ) :
            array(p_name),
            size()
        {}

        virtual std::string getName()
        {
            return array.getName();
        }

        virtual std::string getTypeName()
        {
            return array.getTypeName();
        }

        virtual std::vector<std::string> getRequiredIncludes()
        {
            return T("").getRequiredIncludes();
        }

        T operator[](Int nb)
        {
            return array[nb];
        }

        std::string getDeclaration()
        {
            std::ostringstream sstream;
            sstream << array.getTypeName() << " " << array.getName() << ", ";
            sstream << size.getTypeName() << " " << size.getName();
            return sstream.str();
        }
    protected:
        GlobalArrayVariable<T> array;
        GlobalArrayVariable<Uint> size;
    };
}

