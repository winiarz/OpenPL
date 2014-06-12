#pragma once

#include "boost.hpp"
#include "IInstructionRecorder.hpp"
#include "SingleInstruction.hpp"

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
        IVariable(boost::shared_ptr<IInstructionRecorder> p_recorder) :
            recorder(p_recorder)
        {}

        IVariable(VariableCreateType type,
                  boost::shared_ptr<IInstructionRecorder> p_recorder = boost::shared_ptr<IInstructionRecorder>() )
        {
            switch ( type )
            {
            case SET_LAST_RECORDER_ONLY:
                lastRecorderLock = new std::unique_lock<std::mutex>(lastRecorderMutex);
                lastRecorder = p_recorder;
                break;
            case CREATE_VARIABLE_WITH_LAST_RECORDER:
                recorder = lastRecorder;

                if ( lastRecorderLock != NULL ) 
                    delete lastRecorderLock;
                break;
            }
            
        }

        virtual std::string getName() = 0;
        virtual std::string getTypeName() = 0;

        void recordAssigment( IVariable& rvalue)
        {
            std::ostringstream sstream;
            sstream << getName() << " = " << rvalue.getName();
            (*recorder) << boost::make_shared<SingleInstruction>(sstream.str());
        }

        boost::shared_ptr<IInstructionRecorder> recorder;
    private:
        static std::mutex lastRecorderMutex;
        static std::unique_lock<std::mutex>* lastRecorderLock;
        static boost::shared_ptr<IInstructionRecorder> lastRecorder;
    };

    class IGlobalArrayVariable : public IVariable
    {
    public:
        IGlobalArrayVariable(boost::shared_ptr<IInstructionRecorder> recorder) :
            IVariable(recorder)
        {}
    };
}

