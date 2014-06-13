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

    VectorVariable( int constant ) :
        NumericVariable()
    {
        std::ostringstream stringstream;
        stringstream << constant;
        name = stringstream.str();
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


}

