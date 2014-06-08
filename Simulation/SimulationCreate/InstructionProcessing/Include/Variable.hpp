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

        virtual boost::shared_ptr<IType> getType()
        {
            return boost::make_shared<T>();
        }

        virtual std::string getName()
        {
            return name;
        }
    private:
        std::string name;
    };

    template<class T>
    class GlobalArrayVariable : public IGlobalArrayVariable
    {
        static_assert(std::is_base_of<IType, T>::value, "T not derived from IType");

    public:
        GlobalArrayVariable(std::string p_name, uint p_size = 0) :
            name(p_name),
            size(p_size)
        {}

        virtual boost::shared_ptr<IType> getType()
        {
            return boost::make_shared<GlobalArrayType<T>>();
        }

        virtual std::string getName()
        {
            return name;
        }
    private:
        std::string name;
        uint size;
    };
}

