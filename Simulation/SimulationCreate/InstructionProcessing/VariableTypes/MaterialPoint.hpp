#pragma once

#include "IVariable.hpp"
#include "VectorVariable.hpp"
#include "Float.hpp"

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
    void setForce(Float4);
    Float dist_sq(MaterialPoint);
protected:
        std::string name;
};

}

