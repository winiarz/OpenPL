#pragma once

#define SIMSTEP_EXEC_DEC0( simstepName ) \
    void simstepName( );

#define SIMSTEP_EXEC_DEC1( simstepName, arg1Type ) \
    void simstepName( OPL::SimExec:: I ## arg1Type& );

#define SIMSTEP_EXEC_DEC2( simstepName, arg1Type, arg2Type ) \
    void simstepName( OPL::SimExec:: I ## arg1Type&,  \
                      OPL::SimExec:: I ## arg2Type& );


#define SIMSTEP_EXEC_IMP0( className, simstepName ) \
    void className :: simstepName() \
    { \
        if ( !SIMSTEP_NAME(simstepName) ) \
            SIMSTEP_NAME(simstepName) = className :: SIMSTEP_CREATOR_NAME(simstepName) ->create(); \
        std::vector<ClMemory*> args; \
        SIMSTEP_NAME(simstepName)->execute(args); \
    }


#define SIMSTEP_EXEC_IMP1( className, simstepName, arg1Type, arg1Name ) \
    void className :: simstepName( OPL::SimExec:: I ## arg1Type& p_ ## arg1Name ) \
    { \
        if ( !SIMSTEP_NAME(simstepName) ) \
            SIMSTEP_NAME(simstepName) = className :: SIMSTEP_CREATOR_NAME(simstepName) ->create(); \
        std::vector<ClMemory*> args; \
        args.push_back(& p_ ## arg1Name); \
        SIMSTEP_NAME(simstepName)->execute(args); \
    }

#define SIMSTEP_EXEC_IMP2( className, simstepName, arg1Type, arg1Name, arg2Type, arg2Name ) \
    void className :: simstepName( OPL::SimExec:: I ## arg1Type& p_ ## arg1Name,  \
                                   OPL::SimExec:: I ## arg2Type& p_ ## arg2Name ) \
    { \
        if ( !SIMSTEP_NAME(simstepName) ) \
            SIMSTEP_NAME(simstepName) = className :: SIMSTEP_CREATOR_NAME(simstepName) ->create(); \
        std::vector<ClMemory*> args; \
        args.push_back(& p_ ## arg1Name); \
        args.push_back(& p_ ## arg2Name); \
        SIMSTEP_NAME(simstepName)->execute(args); \
    }
