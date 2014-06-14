#pragma once

#include "NumericVariable.hpp"
#include "scNameGenerator.hpp"

namespace InsPr
{


class Int : public TypedNumericVariable<VARIABLE_TYPE_INT>
{
public:
    Int() : TypedNumericVariable<VARIABLE_TYPE_INT>() {}
    Int(std::string p_name) :
        TypedNumericVariable<VARIABLE_TYPE_INT>(p_name) {}

    Int( TypedNumericVariable<VARIABLE_TYPE_INT> original ) :
        TypedNumericVariable<VARIABLE_TYPE_INT>(original.getName())
    {}

    Int(int constant)
        : TypedNumericVariable<VARIABLE_TYPE_INT>(getConstantName(constant))
    {
    }

    std::string getConstantName(int constant)
    {
        std::ostringstream stringstream;
        stringstream << constant;
        return stringstream.str();
    }
};

class Float : public TypedNumericVariable<VARIABLE_TYPE_FLOAT>
{
public:
    Float() : TypedNumericVariable<VARIABLE_TYPE_FLOAT>() {}
    Float(std::string p_name) :
        TypedNumericVariable<VARIABLE_TYPE_FLOAT>(p_name) {}

    Float( TypedNumericVariable<VARIABLE_TYPE_FLOAT> original ) :
        TypedNumericVariable<VARIABLE_TYPE_FLOAT>(original.getName())
    {}

    Float(float constant)
        : TypedNumericVariable<VARIABLE_TYPE_FLOAT>(getConstantName(constant))
    {}

    std::string getConstantName(float constant)
    {
        std::ostringstream stringstream;
        stringstream << constant;
        return stringstream.str();
    }
};

Int operator%(Int first, Int second);

}
