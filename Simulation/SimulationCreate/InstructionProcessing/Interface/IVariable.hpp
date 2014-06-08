#pragma once

#include "boost.hpp"
#include "IInstructionRecorder.hpp"

namespace InsPr
{
    class IVariable
    {
    public:
        IVariable(boost::shared_ptr<IInstructionRecorder> p_recorder) :
            recorder(p_recorder)
        {}

        virtual std::string getName() = 0;
        virtual std::string getTypeName() = 0;
    protected:
        boost::shared_ptr<IInstructionRecorder> recorder;
    };

    class IArrayVariable : public IVariable
    {
    };

    class IGlobalArrayVariable : public IVariable
    {
    public:
        IGlobalArrayVariable(boost::shared_ptr<IInstructionRecorder> recorder) :
            IVariable(recorder)
        {}
    };
}

