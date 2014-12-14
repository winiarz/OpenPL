#pragma once

#include "IVariable.hpp"
#include "VectorVariable.hpp"

namespace InsPr
{

class MaterialPoint : public IVariable
{
public:
    MaterialPoint();
    MaterialPoint(std::string p_name);

    virtual std::string getName();
    virtual std::string getTypeName();
    virtual std::vector<std::string> getRequiredIncludes();
    MaterialPoint operator=( MaterialPoint rvalue );
    MaterialPoint operator<< ( Float3 force );
    void move();
protected:
        std::string name;
};

}

