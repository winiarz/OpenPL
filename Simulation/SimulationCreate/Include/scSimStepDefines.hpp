#pragma once

#include "scSimStepRecordDefines.hpp"
#include "scSimStepObjectDefines.hpp"
#include "scSimStepCreatorDefines.hpp"
#include "scSimStepCreatorNoArgDefines.hpp"
#include "scSimStepExecDefines.hpp"



#define SIMSTEP_DEF_NOARGPART( simstepName ) \
    SIMSTEP_DEC( simstepName ) \
    SIMSTEP_CREATOR_DEC( simstepName ) \
    RECORD_SIMSTEP_NOARG_DEC( simstepName )

// -------------------- SIM STEP 0 -------------------------

#define SIMSTEP_DEF0( simstepName ) \
    SIMSTEP_EXEC_DEC0( simstepName ) \
    SIMSTEP_DEF_NOARGPART( simstepName ) \
    RECORD_SIMSTEP_DEC0( simstepName )

#define SIMSTEP_IMP0( className, simstepName) \
    SIMSTEP_EXEC_IMP0( className, simstepName ) \
    SIMSTEP_DEF( className, simstepName ) \
    SIMSTEP_CREATOR_DEF( className, simstepName ) \
    RECORD_SIMSTEP_NOARG_IMP0( className, simstepName ) \
    RECORD_SIMSTEP_IMP0( className, simstepName )


// -------------------- SIM STEP 1 -------------------------

#define SIMSTEP_DEF1( simstepName, arg1Type ) \
    SIMSTEP_EXEC_DEC1( simstepName, arg1Type ) \
    SIMSTEP_DEF_NOARGPART( simstepName ) \
    RECORD_SIMSTEP_DEC1( simstepName, arg1Type )

#define SIMSTEP_IMP1( className, simstepName, arg1Type, arg1Name ) \
    SIMSTEP_EXEC_IMP1( className, simstepName, arg1Type, arg1Name ) \
    SIMSTEP_DEF( className, simstepName ) \
    SIMSTEP_CREATOR_DEF( className, simstepName ) \
    RECORD_SIMSTEP_NOARG_IMP1( className, simstepName, arg1Type ) \
    RECORD_SIMSTEP_IMP1( className, simstepName, arg1Type, arg1Name )

// -------------------- SIM STEP 2 -------------------------

#define SIMSTEP_DEF2( simstepName, arg1Type, arg2Type ) \
    SIMSTEP_EXEC_DEC2( simstepName, arg1Type, arg2Type ) \
    SIMSTEP_DEF_NOARGPART( simstepName ) \
    RECORD_SIMSTEP_DEC2( simstepName, arg1Type, arg2Type )

#define SIMSTEP_IMP2( className, simstepName, arg1Type, arg1Name, arg2Type, arg2Name ) \
    SIMSTEP_EXEC_IMP2( className, simstepName, arg1Type, arg1Name, arg2Type, arg2Name ) \
    SIMSTEP_DEF( className, simstepName ) \
    SIMSTEP_CREATOR_DEF( className, simstepName ) \
    RECORD_SIMSTEP_NOARG_IMP2( className, simstepName, arg1Type, arg2Type ) \
    RECORD_SIMSTEP_IMP2( className, simstepName, arg1Type, arg1Name, arg2Type, arg2Name )

