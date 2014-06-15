#pragma once

#include <iostream>

#include "ControlInstructionsDefines.hpp"

#include "scKernelToCreateSet.hpp"
#include "seTypes.hpp"
#include "scTypes.hpp"
#include "scCreateKernel.hpp"

#define MEMORY( type, name, size) OPL::SimExec::type<size> name;


