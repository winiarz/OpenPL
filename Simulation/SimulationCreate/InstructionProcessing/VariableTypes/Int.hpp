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

    Int(int constant) : TypedNumericVariable<VARIABLE_TYPE_INT>()
    {
        std::ostringstream stringstream;
        stringstream << constant;
        name = stringstream.str();
    }
};

Int operator%(Int first, Int second);

}
