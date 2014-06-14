#pragma once

#define RECORD_SIMSTEP_NOARG_NAME( name ) __OPL_SIMSTEP_ ## name ## _NOARG_RECORD

#define RECORD_SIMSTEP_NOARG_DEC( simstepName ) \
    static std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> RECORD_SIMSTEP_NOARG_NAME( simstepName ) ();


#define RECORD_SIMSTEP_NOARG_IMP0( className, simstepName ) \
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> className :: RECORD_SIMSTEP_NOARG_NAME( simstepName ) () \
    {\
        std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments; \
        RECORD_SIMSTEP_NAME(simstepName) (); \
        return arguments; \
    }

#define RECORD_SIMSTEP_NOARG_IMP1( className, simstepName, arg1Type ) \
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> className :: RECORD_SIMSTEP_NOARG_NAME( simstepName ) () \
    {\
        std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments; \
        boost::shared_ptr<InsPr:: arg1Type ## Global> arg_1 = boost::make_shared<InsPr:: arg1Type ## Global> ( ); \
        arguments.push_back( arg_1 ); \
        RECORD_SIMSTEP_NAME(simstepName) ( *arg_1 ); \
        return arguments; \
    }

#define RECORD_SIMSTEP_NOARG_IMP2( className, simstepName, arg1Type, arg2Type ) \
    std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> className :: RECORD_SIMSTEP_NOARG_NAME( simstepName ) () \
    {\
        std::vector<boost::shared_ptr<InsPr::IGlobalArrayVariable>> arguments; \
        boost::shared_ptr<InsPr:: arg1Type ## Global> arg_1 = boost::make_shared<InsPr:: arg1Type ## Global> ( ); \
        boost::shared_ptr<InsPr:: arg2Type ## Global> arg_2 = boost::make_shared<InsPr:: arg2Type ## Global> ( ); \
        arguments.push_back( arg_1 ); \
        arguments.push_back( arg_2 ); \
        RECORD_SIMSTEP_NAME(simstepName) ( *arg_1, *arg_2 ); \
        return arguments; \
    }

