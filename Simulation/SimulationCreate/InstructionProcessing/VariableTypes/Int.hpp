#pragma once

namespace InsPr
{
class Int : public IVariable
{
public:
    Int(std::string p_name = std::string()) :
        name(p_name)
    {}

    virtual std::string getName()
    {
        return name;
    }

    virtual std::string getTypeName()
    {
        return std::string("int");
    }
private:
    std::string name;
};
}
