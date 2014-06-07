#pragma once

/*#define KERNEL_DEF1( kernel_name, arg1_type ) void kernel_name ( I ## arg1_type&);
#define KERNEL_IMP1( class_name, kernel_name, arg1_type, arg1_name )\
void class_name::kernel_name(I ## arg1_type& arg1_name) \
{\
 static ClKernel kernel( createFilename( #class_name, #kernel_name).c_str() , #kernel_name ); \
 if( kernel.isSetUpSuccessfully() )\
 kernel[256][ClPlatform::getPlatform().max_work_group_size](1,&arg1_name);\
}\
\
using namespace OPL::SimCreate;\
class NOT_USED_ ## class_name ## __ ## kernel_name : public OPL::SimCreate::Simulation{\
void NOT_USED( OPL::SimCreate:: arg1_type);\
};\
void NOT_USED_ ## class_name ## __ ## kernel_name :: NOT_USED ( OPL::SimCreate:: arg1_type arg1_name )*/

#define KERNEL_DEF2( kernel_name, arg1_type, arg2_type ) void kernel_name ( I ## arg1_type&, I ## arg2_type&);
#define KERNEL_IMP2( class_name, kernel_name, arg1_type, arg1_name, arg2_type, arg2_name )\
void class_name::kernel_name(I ## arg1_type& arg1_name, I ## arg2_type& arg2_name) \
{\
 ClKernel kernel( createFilename( #class_name, #kernel_name).c_str() , #kernel_name ); \
 if( kernel.isSetUpSuccessfully() )\
 kernel[1][ClPlatform::getPlatform().max_work_group_size](2,&arg1_name,&arg2_name);\
}\
\
using namespace OPL::SimCreate;\
class NOT_USED_ ## class_name ## __ ## kernel_name : public OPL::SimCreate::Simulation{\
void NOT_USED( OPL::SimCreate:: arg1_type,OPL::SimCreate:: arg2_type);\
};\
void NOT_USED_ ## class_name ## __ ## kernel_name :: NOT_USED ( OPL::SimCreate:: arg1_type arg1_name,OPL::SimCreate:: arg2_type arg2_name )

