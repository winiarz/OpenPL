#pragma once

namespace InsPr
{
class Int : public IVariable
{
public:
    Int(boost::shared_ptr<IInstructionRecorder> p_recorder,
        std::string p_name = std::string()) :
        IVariable(p_recorder),
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
