#pragma once

#include "NumericVariable.hpp"
#include "scNameGenerator.hpp"

namespace InsPr
{

typedef TypedNumericVariable<VARIABLE_TYPE_INT> Int;

Int operator%(Int first, Int second);

}
