#pragma once

#define FOR( control_variable, start_value, end_value, loop_command) \
FOR_PARALLEL( control_variable, start_value, end_value );\
print_opening_brace();\
loop_command;\
print_closing_brace();

#define IF( condition ) \
    InsPr::IVariable::recorder->startIf( boost::make_shared<InsPr::SingleInstruction>( InsPr::Int( condition ).getName() ) ); \
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
    InsPr::IVariable::recorder->startWhileLoop( boost::make_shared<InsPr::SingleInstruction>( InsPr::Int( condition ).getName() ) ); \
    for( int __CONTROL_TEMP_VARIABLE__ = 2; __CONTROL_TEMP_VARIABLE__ > 0; -- __CONTROL_TEMP_VARIABLE__ ) \
    if ( __CONTROL_TEMP_VARIABLE__ == 1) \
        InsPr::IVariable::recorder->finishBlock(); \
    else

#define IF_ELSE( condition, if_command, else_command ) \
IF_INSTRUCTION( condition );\
print_opening_brace();\
if_command;\
print_closing_brace();\
ELSE_INSTRUCTION();\
print_opening_brace();\
else_command;\
print_closing_brace();


