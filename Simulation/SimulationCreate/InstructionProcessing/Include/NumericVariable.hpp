#pragma once

#include "IVariable.hpp"
#include "scNameGenerator.hpp"

namespace InsPr
{
    class NumericVariable : public IVariable
    {
    public:
        NumericVariable() :
            IVariable()
        {}

        virtual std::string getName() = 0;
        virtual std::string getTypeName() = 0;
    };

    enum NumericVariableTypes
    {
        VARIABLE_TYPE_INT,
        VARIABLE_TYPE_UINT,
        VARIABLE_TYPE_FLOAT
    };

    std::string getNumericTypeName(NumericVariableTypes type);

    template <NumericVariableTypes type>
    class TypedNumericVariable : public NumericVariable
    {
    public:
    TypedNumericVariable() :
        NumericVariable(),
        name(OPL::SimCreate::NameGenerator::getNameGenerator().nextName())
    {
        recordDeclaration();
    }

    TypedNumericVariable( std::string p_name ) :
        NumericVariable(),
        name(p_name)
    {}

    TypedNumericVariable( const TypedNumericVariable& original ) :
        NumericVariable(),
        name(original.name)
    {}


    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getTypeName()
    {
        return getNumericTypeName(type);
    }
    
    TypedNumericVariable operator=( TypedNumericVariable rvalue )
    {
        recordAssigment(rvalue);
        return *this;
    }
    protected:
        std::string name;
    };



    template<class T>
    T operator+(T first, T second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " + " << second.getName();
        return T( sstream.str());
    }

    template<class T>
    T operator-(T first, T second)
    {
        static_assert(std::is_base_of<NumericVariable, T>(), "T must be NumericVariable!");
        std::ostringstream sstream;
        sstream << first.getName() << " - " << second.getName();
        return T( sstream.str());
    }
}

