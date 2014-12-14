#pragma once

#include "NumericVariable.hpp"
#include "scNameGenerator.hpp"

namespace InsPr
{

class Uint : public TypedNumericVariable<VARIABLE_TYPE_UINT>
{
public:
    Uint() : TypedNumericVariable<VARIABLE_TYPE_UINT>() {}
    Uint(std::string p_name) :
        TypedNumericVariable<VARIABLE_TYPE_UINT>(p_name) {}

    Uint( TypedNumericVariable<VARIABLE_TYPE_UINT> original ) :
        TypedNumericVariable<VARIABLE_TYPE_UINT>(original.getName())
    {}

    Uint(int constant)
        : TypedNumericVariable<VARIABLE_TYPE_UINT>(getConstantName(constant))
    {
    }

    std::string getConstantName(int constant)
    {
        std::ostringstream stringstream;
        stringstream << constant;
        return stringstream.str();
    }
};

Uint operator%( Uint first, Uint second);
Uint operator+( Uint left, Uint right );
Uint operator/( Uint left, Uint right );

}
