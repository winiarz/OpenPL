
#directories


Lib=$(ProjectRoot)/lib

ClPlatform=$(ProjectRoot)/ClPlatform
include $(ClPlatform)/Makefiles/Directories.mk

Common=$(ProjectRoot)/Common
include $(Common)/Makefiles/Directories.mk

Simulation=$(ProjectRoot)/Simulation

SimCreate=$(Simulation)/SimulationCreate
include $(SimCreate)/Makefiles/Directories.mk

SimExecute=$(Simulation)/SimulationExecute
include $(SimExecute)/Makefiles/Directories.mk


#Tool directories
ScriptDir=$(ProjectRoot)/Script

#Code directories
Common=$(ProjectRoot)/Common
SimulationCreate=$(Simulation)/SimulationCreate
SimulationExecute=$(Simulation)/SimulationExecute
KernelLoader=$(SimulationExecute)/KernelLoader

#Binary directories
Obj=$(ProjectRoot)/Obj
Bin=$(ProjectRoot)/Bin
TestBin=$(Bin)/Test

#disable default rules
MAKEFLAGS += --no-builtin-rules

#additional makefiles
Makefiles=$(ProjectRoot)/Makefiles

include $(Makefiles)/IncludeDirectories.mk

# My library files
libClPlatform=$(Lib)/ClPlatform.a
libSimCreate=$(Lib)/SimulationCreate.a
libSimCreateMain=$(Lib)/SimulationCreateMain.a
libInstructionProcessing=$(Lib)/InstructionProcessing.a
libSimExecute=$(Lib)/SimulationExecute.a
libKernelLoader=$(Lib)/KernelLoader.a
libLogs=$(ProjectRoot)/lib/Logs.a

allLibs=$(libSimExecute) $(libSimCreate) $(libClPlatform) $(libInstructionProcessing) $(libLogs)

#compilers and their flags
cpp=g++
cpp_flags=-c -std=c++11 -Wall -Werror 

clcc=$(Bin)/clcc

#external libraries
OpenClLib=/usr/lib/x86_64-linux-gnu/libOpenCL.so.1 -pthread
GTest=-lgtest -lgtest_main
GMock=-lgmock -lgmock_main
OpenGL=-lGL -lGLU -lGLEW 
