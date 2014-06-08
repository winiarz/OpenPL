#pragma once

#include "boost.hpp"
#include "IInstructionRecorder.hpp"
#include "SingleInstruction.hpp"

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

        IVariable& operator=( IVariable& rvalue)
        {
            std::ostringstream sstream;
            sstream << getName() << " = " << rvalue.getName();
            (*recorder) << boost::make_shared<SingleInstruction>(sstream.str());
            return *this;
        }

    protected:
        boost::shared_ptr<IInstructionRecorder> recorder;
    };

    class IGlobalArrayVariable : public IVariable
    {
    public:
        IGlobalArrayVariable(boost::shared_ptr<IInstructionRecorder> recorder) :
            IVariable(recorder)
        {}
    };
}

