#pragma once

#include "NumericVariable.hpp"

namespace InsPr
{
class Int : public NumericVariable
{
public:
    Int(boost::shared_ptr<IInstructionRecorder> p_recorder,
        std::string p_name ) :
        NumericVariable(p_recorder),
        name(p_name)
    {}

    Int(boost::shared_ptr<IInstructionRecorder> p_recorder) :
        NumericVariable(SET_LAST_RECORDER_ONLY, p_recorder)
    {}

    Int( int constant ) :
        NumericVariable(boost::shared_ptr<IInstructionRecorder>())
    {
        std::ostringstream stringstream;
        stringstream << constant;
        name = stringstream.str();
    }
        
    Int(std::string p_name) :
        NumericVariable(CREATE_VARIABLE_WITH_LAST_RECORDER),
        name(p_name)
    {}

    Int( const Int& original ) :
        NumericVariable(original.recorder),
        name(original.name)
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
