#pragma once

#define SIMSTEP_CREATOR_NAME( name ) __OPL_SIMSTEP_ ## name ## _CREATOR

#define SIMSTEP_CREATOR_DEC( simstepName ) \
    static shared_ptr<ISimStepCreator> SIMSTEP_CREATOR_NAME(simstepName) ;

#define SIMSTEP_CREATOR_DEF( className, simstepName ) \
    shared_ptr<ISimStepCreator> className :: SIMSTEP_CREATOR_NAME(simstepName) = \
    make_shared<SimStepCreator>( \
       &className :: RECORD_SIMSTEP_NOARG_NAME(simstepName), \
       std::vector<shared_ptr<InsPr::IGlobalArrayVariable>>() ) ;

