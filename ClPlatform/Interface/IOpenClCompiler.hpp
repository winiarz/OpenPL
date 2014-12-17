#pragma once
#include <string>
#include <CL/cl.h>

namespace OPL
{

class IOpenClCompiler
{
public:
    virtual cl_program compile(std::string&) const = 0;
};

}

