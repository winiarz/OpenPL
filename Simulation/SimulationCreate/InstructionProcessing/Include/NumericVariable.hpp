#pragma once

#include "IVariable.hpp"

namespace InsPr
{
class NumericVariable : public IVariable
{
public:
    NumericVariable(boost::shared_ptr<IInstructionRecorder> recorder) :
        IVariable(recorder)
    {}

    virtual std::string getName() = 0;
    virtual std::string getTypeName() = 0;
};
}

