#pragma once

#include "NumericVariable.hpp"
#include "scNameGenerator.hpp"

namespace OPL
{
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

Int operator%(Int first, Int second);
Int operator+( Int left, Int right );
Int operator/( Int left, Int right );
Int SizeOf( IVariable& );

template <NumericVariableTypes type>
Int operator<( TypedNumericVariable<type> left, TypedNumericVariable<type> right )
{
    std::ostringstream sstream;
    sstream << left.getName() << " < " << right.getName();
    return Int( sstream.str());
}

template <NumericVariableTypes type>
Int operator>( TypedNumericVariable<type> left, TypedNumericVariable<type> right )
{
    std::ostringstream sstream;
    sstream << left.getName() << " > " << right.getName();
    return Int( sstream.str());
}



}
}

