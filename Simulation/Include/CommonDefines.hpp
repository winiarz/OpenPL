#pragma once

#include <iostream>

#include "ControlInstructionsDefines.hpp"

#include "scKernelToCreateSet.hpp"
#include "seTypes.hpp"
#include "scTypes.hpp"
#include "scCreateKernel.hpp"

#define MEMORY( type, name, size) OPL::SimExec::type<size> name;

// ----------- KERNEL DEF/IMP 1

#define KERNEL_DEF1( kernel_name, arg1 ) \
	      static void __OPL_ ## kernel_name( OPL::SimCreate:: arg1);\
              void kernel_name( OPL::SimExec:: I ## arg1&);\
              static ClKernel* __OPL_KERNEL_ ## kernel_name;

#define KERNEL_IMP1( class_name, kernel_name, arg1_type, arg1_name ) \
ClKernel* class_name::__OPL_KERNEL_ ## kernel_name = NULL;\
void class_name :: kernel_name(OPL::SimExec:: I ## arg1_type& arg1_name)\
{\
  OPL::SimCreate::KernelToCreateSet::getKernelToCreateSet().loadAndRunKernel1( &__OPL_KERNEL_ ## kernel_name, #kernel_name, OPL::SimCreate::CreateKernel::createFileName( #class_name, #kernel_name), &arg1_name);\
}\
class KERNEL_CREATOR_ ## class_name ## _ ## kernel_name : public OPL::SimCreate::CreateKernel {\
public:\
  KERNEL_CREATOR_ ## class_name ## _ ## kernel_name() : OPL::SimCreate::CreateKernel( #class_name , #kernel_name )\
  { OPL::SimCreate::KernelToCreateSet::getKernelToCreateSet().addKernel(this); }\
  int createKernel()\
  {\
    start( #kernel_name );  \
    addArg(OPL::SimCreate::arg1_type::getTypeName(), #arg1_name); \
    endOfArgs();  \
    OPL::SimCreate:: arg1_type arg1_name( #arg1_name );\
    class_name :: __OPL_ ## kernel_name(arg1_name);\
    createBinaryFile();\
    return 0;\
  }\
}_KERNEL_ ## class_name ## _ ## kernel_name;\
using namespace OPL::SimCreate;\
void class_name :: __OPL_ ## kernel_name(OPL::SimCreate:: arg1_type arg1_name)

// ----------- KERNEL DEF/IMP 2

#define KERNEL_DEF2( kernel_name, arg1, arg2 ) \
	      static void __OPL_ ## kernel_name( OPL::SimCreate:: arg1, OPL::SimCreate:: arg2);\
              void kernel_name( OPL::SimExec:: I ## arg1&, OPL::SimExec:: I ## arg2&);\
              static ClKernel* __OPL_KERNEL_ ## kernel_name;

#define KERNEL_IMP2( class_name, kernel_name, arg1_type, arg1_name, arg2_type, arg2_name ) \
ClKernel* class_name::__OPL_KERNEL_ ## kernel_name = NULL;\
void class_name :: kernel_name(OPL::SimExec:: I ## arg1_type& arg1_name, OPL::SimExec:: I ## arg2_type& arg2_name)\
{\
  OPL::SimCreate::KernelToCreateSet::getKernelToCreateSet().loadAndRunKernel2( &__OPL_KERNEL_ ## kernel_name, #kernel_name, OPL::SimCreate::CreateKernel::createFileName( #class_name, #kernel_name), &arg1_name, &arg2_name);\
}\
class KERNEL_CREATOR_ ## class_name ## _ ## kernel_name : public OPL::SimCreate::CreateKernel {\
public:\
  KERNEL_CREATOR_ ## class_name ## _ ## kernel_name() : OPL::SimCreate::CreateKernel( #class_name , #kernel_name )\
  { OPL::SimCreate::KernelToCreateSet::getKernelToCreateSet().addKernel(this); }\
  int createKernel()\
  {\
    start( #kernel_name );  \
    addArg(OPL::SimCreate::arg1_type::getTypeName(), #arg1_name); \
    addArg(OPL::SimCreate::arg2_type::getTypeName(), #arg2_name); \
    endOfArgs();  \
    OPL::SimCreate:: arg1_type arg1_name( #arg1_name );\
    OPL::SimCreate:: arg2_type arg2_name( #arg2_name );\
    class_name :: __OPL_ ## kernel_name(arg1_name, arg2_name);\
    createBinaryFile();\
    return 0;\
  }\
}_KERNEL_ ## class_name ## _ ## kernel_name;\
using namespace OPL::SimCreate;\
void class_name :: __OPL_ ## kernel_name(OPL::SimCreate:: arg1_type arg1_name, OPL::SimCreate:: arg2_type arg2_name)

