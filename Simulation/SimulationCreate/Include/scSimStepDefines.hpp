#pragma once

using namespace OPL::SimCreate;
using namespace OPL::SimExec;
using namespace InsPr;

#define RECORD_SIMSTEP_NAME( name ) __OPL_SIMSTEP_ ## name ## _RECORD

#define RECORD_SIMSTEP_DEC( simstepName ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ();

#define RECORD_SIMSTEP_IMP( className, simstepName ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )()



#define SIMSTEP_NAME( name ) __OPL_SIMSTEP_ ## name

#define SIMSTEP_DEC( simstepName ) \
    static boost::shared_ptr<ISimStep> SIMSTEP_NAME(simstepName);

#define SIMSTEP_DEF( className, simstepName ) \
    boost::shared_ptr<ISimStep> className :: SIMSTEP_NAME(simstepName) = \
    boost::shared_ptr<ISimStep>();


#define SIMSTEP_RECORDER_NAME( name ) __OPL_SIMSTEP_ ## name ## _RECORDER

#define SIMSTEP_RECORDER_DEC( simstepName ) \
    static boost::shared_ptr<IInstructionRecorder> SIMSTEP_RECORDER_NAME( simstepName );

#define SIMSTEP_RECORDER_DEF( className, simstepName ) \
    boost::shared_ptr<IInstructionRecorder> className :: SIMSTEP_RECORDER_NAME( simstepName ) = \
    boost::make_shared<InstructionRecorder>();


#define SIMSTEP_CREATOR_NAME( name ) __OPL_SIMSTEP_ ## name ## _CREATOR

#define SIMSTEP_CREATOR_DEC( simstepName ) \
    static boost::shared_ptr<ISimStepCreator> SIMSTEP_CREATOR_NAME(simstepName) ;

#define SIMSTEP_CREATOR_DEF0( className, simstepName ) \
    boost::shared_ptr<ISimStepCreator> className :: SIMSTEP_CREATOR_NAME(simstepName) = \
    boost::make_shared<SimStepCreator>( \
       &className :: RECORD_SIMSTEP_NAME(simstepName), \
       std::vector<boost::shared_ptr<IGlobalArrayVariable>>(), \
       className :: SIMSTEP_RECORDER_NAME(simstepName) ) ;



#define SIMSTEP_DEF0( simstepName ) \
    void simstepName(); \
    SIMSTEP_DEC( simstepName ) \
    SIMSTEP_RECORDER_DEC( simstepName ) \
    SIMSTEP_CREATOR_DEC( simstepName ) \
    RECORD_SIMSTEP_DEC( simstepName )

#define SIMSTEP_IMP0( className, simstepName ) \
    void className :: simstepName() \
    { \
        if ( !SIMSTEP_NAME(simstepName) ) \
            SIMSTEP_NAME(simstepName) = className :: SIMSTEP_CREATOR_NAME(simstepName) ->create(); \
        std::vector<boost::shared_ptr<ClMemory>> args; \
        SIMSTEP_NAME(simstepName)->execute(args); \
    } \
    SIMSTEP_DEF( className, simstepName ) \
    SIMSTEP_RECORDER_DEF( className, simstepName ) \
    SIMSTEP_CREATOR_DEF0( className, simstepName ) \
    RECORD_SIMSTEP_IMP( className, simstepName )



