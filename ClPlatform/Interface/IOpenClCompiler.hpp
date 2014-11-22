#pragma once
#include <string>
#include <CL/cl.h>

class IOpenClCompiler
{
public:
    virtual cl_program compile(std::string&) const = 0;
};
