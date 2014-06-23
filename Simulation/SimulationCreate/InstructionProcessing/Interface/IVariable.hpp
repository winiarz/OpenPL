#pragma once

#include "boost.hpp"
#include "IInstructionRecorder.hpp"
#include "SingleInstruction.hpp"
#include "IVariable.hpp"

namespace InsPr
{
    enum VariableCreateType
    {
        CREATE_VARIABLE_WITH_LAST_RECORDER=0,
        SET_LAST_RECORDER_ONLY=1
    };

    class IVariable
    {
    public:
        IVariable()
        {}

        virtual std::string getName() = 0;
        virtual std::string getTypeName() = 0;
        virtual std::vector<std::string> getRequiredIncludes()
        {
            return std::vector<std::string>();
        }

        void recordAssigment( IVariable& rvalue)
        {
            std::ostringstream sstream;
            sstream << getName() << " = " << rvalue.getName();
            (*recorder) << std::make_shared<SingleInstruction>(sstream.str());
        }

        void recordDeclaration()
        {
            std::ostringstream sstream;
            sstream << getTypeName() << " " << getName();
            (*recorder) << std::make_shared<SingleInstruction>(sstream.str());
        }

        static std::shared_ptr<IInstructionRecorder> recorder;
    };

    class IGlobalArrayVariable : public IVariable
    {
    public:
        IGlobalArrayVariable() :
            IVariable()
        {}
    };
}

