
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(InstructionProcessing)/Makefiles/InstructionProcessing.mk
include $(SimExecute)/SimExecute.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute) $(libInstructionProcessing)

CompileTest: $(ClPlatform)/TestPlatform $(ClPlatformTestKernels) Bin/Test/InstructionProcessingTS

test: ClPlatformTest InstructionProcessingTest CommonTest

clean:
	@rm -f lib/*.a $(filesToClean)

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
