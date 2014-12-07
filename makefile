
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(InstructionProcessing)/Makefiles/InstructionProcessing.mk
include $(SimExecute)/SimExecute.mk

include Test/empty_sim/Empty_Simulation.mk
include Test/declare_memory/Declare_Memory.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute) $(libInstructionProcessing)

CompileTest: $(TestBinaries)

test: ClPlatformTest InstructionProcessingTest CommonTest EmptySimulationTest DeclareMemoryTest

clean:
	@rm -f lib/*.a $(filesToClean)

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
