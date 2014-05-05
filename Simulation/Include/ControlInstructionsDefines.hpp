#ifndef __CONTROL_INSTRUCTIONS_DEFINES__
#define __CONTROL_INSTRUCTIONS_DEFINES__

#define FOR( control_variable, start_value, end_value, loop_command) \
FOR_PARALLEL( control_variable, start_value, end_value );\
print_opening_brace();\
loop_command;\
print_closing_brace();

#define IF( condition, if_command ) \
IF_INSTRUCTION( condition );\
print_opening_brace();\
if_command;\
print_closing_brace();

#define IF_ELSE( condition, if_command, else_command ) \
IF_INSTRUCTION( condition );\
print_opening_brace();\
if_command;\
print_closing_brace();\
ELSE_INSTRUCTION();\
print_opening_brace();\
else_command;\
print_closing_brace();

#define WHILE( condition, command ) \
WHILE_INSTRUCTION( condition );\
print_opening_brace();\
command;\
print_closing_brace();

#endif
