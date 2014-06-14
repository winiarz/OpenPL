#pragma once

#define SIMSTEP_NAME( name ) __OPL_SIMSTEP_ ## name

#define SIMSTEP_DEC( simstepName ) \
    static boost::shared_ptr<ISimStep> SIMSTEP_NAME(simstepName);

#define SIMSTEP_DEF( className, simstepName ) \
    boost::shared_ptr<ISimStep> className :: SIMSTEP_NAME(simstepName) = \
    boost::shared_ptr<ISimStep>();

