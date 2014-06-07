#pragma once

#include "scKernelToCreateSet.hpp"

/*#define KERNEL_DEF1( kernel_name, arg1 ) static void kernel_name(arg1);
#define KERNEL_IMP1( class_name, kernel_name, arg1_type, arg1_name )\
class KERNEL_ ## class_name ## _ ## kernel_name : public OPL::SimCreate::CreateKernel {\
public:\
  KERNEL_ ## class_name ## _ ## kernel_name() : OPL::SimCreate::CreateKernel( #class_name , #kernel_name )\
  { KernelToCreateSet::getKernelToCreateSet().addKernel(this); }\
  int createKernel()\
  {\
    start( #kernel_name );  \
    addArg(arg1_type::getTypeName(), #arg1_name); \
    endOfArgs();  \
    arg1_type arg1_name( #arg1_name );\
    class_name :: kernel_name(arg1_name);\
    createBinaryFile();\
    return 0;\
  }\
}_KERNEL_ ## class_name ## _ ## kernel_name;\
void class_name :: kernel_name(arg1_type arg1_name) */

#define KERNEL_DEF2( kernel_name, arg1, arg2 ) static void kernel_name(arg1,arg2);
#define KERNEL_IMP2( class_name, kernel_name, arg1_type, arg1_name, arg2_type, arg2_name )\
class KERNEL_ ## class_name ## _ ## kernel_name : public OPL::SimCreate::CreateKernel {\
public:\
  KERNEL_ ## class_name ## _ ## kernel_name() : OPL::SimCreate::CreateKernel( #class_name , #kernel_name )\
  { KernelToCreateSet::getKernelToCreateSet().addKernel(this); }\
  int createKernel()\
  {\
    start( #kernel_name );  \
    addArg(arg1_type::getTypeName(), #arg1_name); \
    addArg(arg2_type::getTypeName(), #arg2_name); \
    endOfArgs();  \
    arg1_type arg1_name( #arg1_name );\
    arg2_type arg2_name( #arg2_name );\
    class_name :: kernel_name(arg1_name, arg2_name);\
    createBinaryFile();\
    return 0;\
  }\
}_KERNEL_ ## class_name ## _ ## kernel_name;\
void class_name :: kernel_name(arg1_type arg1_name, arg2_type arg2_name)

