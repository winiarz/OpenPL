#pragma once

#include "IVariable.hpp"
#include "VectorVariable.hpp"

namespace InsPr
{

class MaterialPoint : public IVariable
{
public:
    MaterialPoint() : IVariable() {}
    MaterialPoint(std::string p_name) :
        name(p_name) {}

    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getTypeName()
    {
        return "struct MaterialPoint";
    }

    virtual std::vector<std::string> getRequiredIncludes()
    {
        std::vector<std::string> result;
        result.push_back("material_point.cl");
        return result;
    }
    
    MaterialPoint operator=( MaterialPoint rvalue )
    {
        recordAssigment(rvalue);
        return *this;
    }

    MaterialPoint operator<< ( Float3 force )
    {
        std::ostringstream sstream;
        sstream << getName() << ".force += (float4)(" << force.getName() << ",0)";
        (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
        return *this;
    }

    void move()
    {
        InsPr::IVariable::recorder->addInclude("material_point_move.cl");
        std::ostringstream sstream;
        sstream << "material_point_move ( &" << getName() << ",0,1,1 );\n";
        (*IVariable::recorder) << make_shared<SingleInstruction>(sstream.str());
    }
protected:
        std::string name;
};

}

