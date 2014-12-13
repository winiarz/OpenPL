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
        virtual std::vector<std::string> getRequiredIncludes();

        void recordAssigment( IVariable& rvalue);
        virtual std::string getDeclaration();
        void recordDeclaration();

        static shared_ptr<IInstructionRecorder> recorder;
    };

    class IGlobalArrayVariable : public IVariable
    {
    public:
        IGlobalArrayVariable() :
            IVariable()
        {}
    };
}

