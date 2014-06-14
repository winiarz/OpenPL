#pragma once

#include "NumericVariable.hpp"

namespace InsPr
{

enum VectorVariableSize
{
    VECTOR_VARIABLE_SIZE_2 = 2,
    VECTOR_VARIABLE_SIZE_3 = 3,
    VECTOR_VARIABLE_SIZE_4 = 4
};

uint getVectorVariableSize(VectorVariableSize size);

template <NumericVariableTypes type, VectorVariableSize size>
class VectorVariable : public NumericVariable
{
public:
    VectorVariable() :
        NumericVariable(),
        name(OPL::SimCreate::NameGenerator::getNameGenerator().nextName())
    {
        recordDeclaration();
    }
        
    VectorVariable(std::string p_name) :
        NumericVariable(),
        name(p_name)
    {}

    VectorVariable( const VectorVariable& original ) :
        NumericVariable(),
        name(original.name)
    {}


    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getTypeName()
    {
        std::ostringstream sstream;
        sstream << getNumericTypeName(type) << getVectorVariableSize(size);
        return sstream.str();
    }
    
    VectorVariable operator=( VectorVariable rvalue )
    {
        recordAssigment(rvalue);
        return *this;
    }
    private:
        std::string name;
};

typedef VectorVariable<VARIABLE_TYPE_INT, VECTOR_VARIABLE_SIZE_2> Int2;
typedef VectorVariable<VARIABLE_TYPE_INT, VECTOR_VARIABLE_SIZE_3> Int3;
typedef VectorVariable<VARIABLE_TYPE_INT, VECTOR_VARIABLE_SIZE_4> Int4;

typedef VectorVariable<VARIABLE_TYPE_FLOAT, VECTOR_VARIABLE_SIZE_2> Float2;
typedef VectorVariable<VARIABLE_TYPE_FLOAT, VECTOR_VARIABLE_SIZE_3> Float3;
typedef VectorVariable<VARIABLE_TYPE_FLOAT, VECTOR_VARIABLE_SIZE_4> Float4;

#include "Int.hpp"

template <NumericVariableTypes type>
TypedNumericVariable<type> operator*(TypedNumericVariable<type> first, TypedNumericVariable<type> second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " * " << second.getName();
    return TypedNumericVariable<type>( sstream.str());
}

template <NumericVariableTypes type, VectorVariableSize size>
VectorVariable<type,size> operator*(VectorVariable<type,size> first, TypedNumericVariable<type> second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " * " << second.getName();
    return VectorVariable<type,size>( sstream.str());
}

template <NumericVariableTypes type, VectorVariableSize size>
VectorVariable<type,size> operator*(TypedNumericVariable<type> first, VectorVariable<type,size> second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " * " << second.getName();
    return VectorVariable<type,size>( sstream.str());
}

template <NumericVariableTypes type, VectorVariableSize size>
TypedNumericVariable<type> operator*(VectorVariable<type,size> first, VectorVariable<type,size> second)
{
    std::ostringstream sstream;
    sstream << " ( ";
    for (uint i=0; i<getVectorVariableSize(size); i++) 
    {
        sstream << first.getName() << ".s" << i << " * " << second.getName() << ".s" << i ;
        if ( i < getVectorVariableSize(size)-1 ) 
        {
            sstream << " + ";
        }
    }

    sstream << " ) ";
    return TypedNumericVariable<type>( sstream.str());
}

template <NumericVariableTypes type>
TypedNumericVariable<type> operator/(TypedNumericVariable<type> first, TypedNumericVariable<type> second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " / " << second.getName();
    return TypedNumericVariable<type>( sstream.str());
}

template <NumericVariableTypes type, VectorVariableSize size>
VectorVariable<type,size> operator/(VectorVariable<type,size> first, TypedNumericVariable<type> second)
{
    std::ostringstream sstream;
    sstream << first.getName() << " / " << second.getName();
    return VectorVariable<type,size>( sstream.str());
}

VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3> // TODO: make it a template
    operator^ (VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3> first,
               VectorVariable<VARIABLE_TYPE_FLOAT,VECTOR_VARIABLE_SIZE_3> second);

}

