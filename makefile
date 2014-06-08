
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(InstructionProcessing)/Makefiles/InstructionProcessing.mk
include $(SimExecute)/SimExecute.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute) $(libInstructionProcessing)

CompileTest: $(ClPlatform)/TestPlatform $(ClPlatformTestKernels)

test: ClPlatformTest InstructionProcessingTest

clean: ClPlatformClean CommonClean SimCreateClean SimExecuteClean
	@rm -f lib/*.a

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
