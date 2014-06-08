#pragma once

#include "IVariable.hpp"
#include "ArrayType.hpp"

namespace InsPr
{
    template<class T>
    class Variable : public IVariable
    {
        static_assert(std::is_base_of<IType, T>::value, "T not derived from IType");

    public:
        Variable(std::string p_name) :
            name(p_name)
        {}

        virtual std::string getName()
        {
            return name;
        }

        virtual std::string getTypeName()
        {
            return std::string();
        }
    private:
        std::string name;
    };

    template<class T>
    class GlobalArrayVariable : public IGlobalArrayVariable
    {
    public:
        GlobalArrayVariable(std::string p_name, uint p_size = 0) :
            name(p_name),
            size(p_size)
        {}

        virtual std::string getName()
        {
            return name;
        }

        virtual std::string getTypeName()
        {
            std::ostringstream sstream;
            sstream << "__global " << T().getTypeName() << "*";
            return sstream.str();
        }
    private:
        std::string name;
        uint size;
    };
}

