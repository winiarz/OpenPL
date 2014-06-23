#pragma once

#define IF( condition ) \
    InsPr::IVariable::recorder->startIf( std::make_shared<InsPr::SingleInstruction>( InsPr::Int( condition ).getName() ) ); \
    for( int __CONTROL_TEMP_VARIABLE__ = 2; __CONTROL_TEMP_VARIABLE__ > 0; -- __CONTROL_TEMP_VARIABLE__ ) \
    if ( __CONTROL_TEMP_VARIABLE__ == 1) \
        InsPr::IVariable::recorder->finishBlock(); \
    else

#define ELSE \
    InsPr::IVariable::recorder->startElse(); \
    for( int __CONTROL_TEMP_VARIABLE__ = 2; __CONTROL_TEMP_VARIABLE__ > 0; -- __CONTROL_TEMP_VARIABLE__ ) \
    if ( __CONTROL_TEMP_VARIABLE__ == 1) \
        InsPr::IVariable::recorder->finishBlock(); \
    else

#define WHILE( condition ) \
    InsPr::IVariable::recorder->startWhileLoop( std::make_shared<InsPr::SingleInstruction>( InsPr::Int( condition ).getName() ) ); \
    for( int __CONTROL_TEMP_VARIABLE__ = 2; __CONTROL_TEMP_VARIABLE__ > 0; -- __CONTROL_TEMP_VARIABLE__ ) \
    if ( __CONTROL_TEMP_VARIABLE__ == 1) \
        InsPr::IVariable::recorder->finishBlock(); \
    else

#define FOR( startInstruction, condition, endInstruction) \
    startInstruction ; \
    InsPr::IVariable::recorder->startWhileLoop( std::make_shared<InsPr::SingleInstruction>( InsPr::Int( condition ).getName() ) ); \
    for( int __CONTROL_TEMP_VARIABLE__ = 3; __CONTROL_TEMP_VARIABLE__ > 0; -- __CONTROL_TEMP_VARIABLE__ ) \
    if ( __CONTROL_TEMP_VARIABLE__ == 1) \
        InsPr::IVariable::recorder->finishBlock(); \
    else if (__CONTROL_TEMP_VARIABLE__ == 2 ) \
        endInstruction ; \
    else

