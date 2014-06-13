#pragma once

using namespace OPL::SimCreate;
using namespace OPL::SimExec;

#define RECORD_SIMSTEP_NAME( name ) __OPL_SIMSTEP_ ## name ## _RECORD

#define RECORD_SIMSTEP_DEC( simstepName ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ();

#define RECORD_SIMSTEP_IMP( className, simstepName ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )()

#define RECORD_SIMSTEP_NOARG_NAME( name ) __OPL_SIMSTEP_ ## name ## _NOARG_RECORD



#define SIMSTEP_NAME( name ) __OPL_SIMSTEP_ ## name

#define SIMSTEP_DEC( simstepName ) \
    static boost::shared_ptr<ISimStep> SIMSTEP_NAME(simstepName);

#define SIMSTEP_DEF( className, simstepName ) \
    boost::shared_ptr<ISimStep> className :: SIMSTEP_NAME(simstepName) = \
    boost::shared_ptr<ISimStep>();


#define SIMSTEP_RECORDER_NAME( name ) __OPL_SIMSTEP_ ## name ## _RECORDER

#define SIMSTEP_RECORDER_DEC( simstepName ) \
    static boost::shared_ptr<InsPr::IInstructionRecorder> SIMSTEP_RECORDER_NAME( simstepName );

#define SIMSTEP_RECORDER_DEF( className, simstepName ) \
    boost::shared_ptr<InsPr::IInstructionRecorder> className :: SIMSTEP_RECORDER_NAME( simstepName ) = \
    boost::make_shared<InsPr::InstructionRecorder>();


#define SIMSTEP_CREATOR_NAME( name ) __OPL_SIMSTEP_ ## name ## _CREATOR

#define SIMSTEP_CREATOR_DEC( simstepName ) \
    static boost::shared_ptr<ISimStepCreator> SIMSTEP_CREATOR_NAME(simstepName) ;

// -------------------- SIM STEP 0 -------------------------

#define RECORD_SIMSTEP_DEC0( simstepName ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ();

#define RECORD_SIMSTEP_IMP0( className, simstepName ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )()


#define RECORD_SIMSTEP_NOARG_DEC0( simstepName ) \
    static std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> RECORD_SIMSTEP_NOARG_NAME( simstepName ) ();

#define RECORD_SIMSTEP_NOARG_IMP0( className, simstepName ) \
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> className :: RECORD_SIMSTEP_NOARG_NAME( simstepName ) () \
    {\
        std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments; \
        RECORD_SIMSTEP_NAME(simstepName) (); \
        return arguments; \
    }

#define SIMSTEP_CREATOR_DEF0( className, simstepName ) \
    boost::shared_ptr<ISimStepCreator> className :: SIMSTEP_CREATOR_NAME(simstepName) = \
    boost::make_shared<SimStepCreator>( \
       &className :: RECORD_SIMSTEP_NOARG_NAME(simstepName), \
       std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>(), \
       className :: SIMSTEP_RECORDER_NAME(simstepName) ) ;

#define SIMSTEP_DEF0( simstepName ) \
    void simstepName( ); \
    SIMSTEP_DEC( simstepName ) \
    SIMSTEP_RECORDER_DEC( simstepName ) \
    SIMSTEP_CREATOR_DEC( simstepName ) \
    RECORD_SIMSTEP_NOARG_DEC0( simstepName ) \
    RECORD_SIMSTEP_DEC0( simstepName )

#define SIMSTEP_IMP0( className, simstepName) \
    void className :: simstepName() \
    { \
        if ( !SIMSTEP_NAME(simstepName) ) \
            SIMSTEP_NAME(simstepName) = className :: SIMSTEP_CREATOR_NAME(simstepName) ->create(); \
        std::vector<ClMemory*> args; \
        SIMSTEP_NAME(simstepName)->execute(args); \
    } \
    SIMSTEP_DEF( className, simstepName ) \
    SIMSTEP_RECORDER_DEF( className, simstepName ) \
    SIMSTEP_CREATOR_DEF0( className, simstepName ) \
    RECORD_SIMSTEP_NOARG_IMP0( className, simstepName ) \
    RECORD_SIMSTEP_IMP0( className, simstepName )


// -------------------- SIM STEP 1 -------------------------

#define RECORD_SIMSTEP_DEC1( simstepName, arg1Type ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ( InsPr:: arg1Type ## Global );

#define RECORD_SIMSTEP_IMP1( className, simstepName, arg1Type, arg1Name ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )( InsPr:: arg1Type ## Global arg1Name )


#define RECORD_SIMSTEP_NOARG_DEC1( simstepName ) \
    static std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> RECORD_SIMSTEP_NOARG_NAME( simstepName ) ();

#define RECORD_SIMSTEP_NOARG_IMP1( className, simstepName, arg1Type ) \
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> className :: RECORD_SIMSTEP_NOARG_NAME( simstepName ) () \
    {\
        std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments; \
        boost::shared_ptr<InsPr:: arg1Type ## Global> arg_1 = boost::make_shared<InsPr:: arg1Type ## Global> ( ); \
        arguments.push_back( arg_1 ); \
        RECORD_SIMSTEP_NAME(simstepName) ( *arg_1 ); \
        return arguments; \
    }

#define SIMSTEP_CREATOR_DEF1( className, simstepName, arg1Type ) \
    boost::shared_ptr<ISimStepCreator> className :: SIMSTEP_CREATOR_NAME(simstepName) = \
    boost::make_shared<SimStepCreator>( \
       &className :: RECORD_SIMSTEP_NOARG_NAME(simstepName), \
       std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>>(), \
       className :: SIMSTEP_RECORDER_NAME(simstepName) ) ;


#define SIMSTEP_DEF1( simstepName, arg1Type ) \
    void simstepName( OPL::SimExec:: I ## arg1Type& ); \
    SIMSTEP_DEC( simstepName ) \
    SIMSTEP_RECORDER_DEC( simstepName ) \
    SIMSTEP_CREATOR_DEC( simstepName ) \
    RECORD_SIMSTEP_NOARG_DEC1( simstepName ) \
    RECORD_SIMSTEP_DEC1( simstepName, arg1Type )

#define SIMSTEP_IMP1( className, simstepName, arg1Type, arg1Name ) \
    void className :: simstepName( OPL::SimExec:: I ## arg1Type& p_ ## arg1Name ) \
    { \
        if ( !SIMSTEP_NAME(simstepName) ) \
            SIMSTEP_NAME(simstepName) = className :: SIMSTEP_CREATOR_NAME(simstepName) ->create(); \
        std::vector<ClMemory*> args; \
        args.push_back(& p_ ## arg1Name); \
        SIMSTEP_NAME(simstepName)->execute(args); \
    } \
    SIMSTEP_DEF( className, simstepName ) \
    SIMSTEP_RECORDER_DEF( className, simstepName ) \
    SIMSTEP_CREATOR_DEF1( className, simstepName, arg1Type ) \
    RECORD_SIMSTEP_NOARG_IMP1( className, simstepName, arg1Type ) \
    RECORD_SIMSTEP_IMP1( className, simstepName, arg1Type, arg1Name )

