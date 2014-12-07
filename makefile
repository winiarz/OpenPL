
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(InstructionProcessing)/Makefiles/InstructionProcessing.mk
include $(SimExecute)/SimExecute.mk

include Test/empty_sim/Empty_Simulation.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute) $(libInstructionProcessing)

CompileTest: $(ClPlatform)/TestPlatform $(ClPlatformTestKernels) Bin/Test/InstructionProcessingTS Bin/Test/Empty_Simulation

test: ClPlatformTest InstructionProcessingTest CommonTest EmptySimulationTest

clean:
	@rm -f lib/*.a $(filesToClean)

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
