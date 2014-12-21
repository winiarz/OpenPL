#pragma once

#define RECORD_SIMSTEP_NAME( name ) __OPL_SIMSTEP_ ## name ## _RECORD


#define RECORD_SIMSTEP_DEC0( simstepName ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ();

#define RECORD_SIMSTEP_DEC1( simstepName, arg1Type ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ( OPL::InsPr:: arg1Type ## Global );

#define RECORD_SIMSTEP_DEC2( simstepName, arg1Type, arg2Type ) \
    static void RECORD_SIMSTEP_NAME( simstepName ) ( OPL::InsPr:: arg1Type ## Global, \
                                                     OPL::InsPr:: arg2Type ## Global );


#define RECORD_SIMSTEP_IMP0( className, simstepName ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )()

#define RECORD_SIMSTEP_IMP1( className, simstepName, arg1Type, arg1Name ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )( OPL::InsPr:: arg1Type ## Global arg1Name )

#define RECORD_SIMSTEP_IMP2( className, simstepName, arg1Type, arg1Name, arg2Type, arg2Name ) \
    void className :: RECORD_SIMSTEP_NAME( simstepName )( OPL::InsPr:: arg1Type ## Global arg1Name, \
                                                          OPL::InsPr:: arg2Type ## Global arg2Name )

