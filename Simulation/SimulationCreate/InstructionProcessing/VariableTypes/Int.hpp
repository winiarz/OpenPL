#pragma once

#include "NumericVariable.hpp"

namespace InsPr
{
class Int : public NumericVariable
{
public:
    Int(boost::shared_ptr<IInstructionRecorder> p_recorder,
        std::string p_name = std::string()) :
        NumericVariable(p_recorder),
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
    
    Int operator=( Int rvalue )
    {
        recordAssigment(rvalue);
        return *this;
    }
private:
    std::string name;
};
}
