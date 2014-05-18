
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(SimExecute)/SimExecute.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute)

CompileTest: $(ClPlatform)/TestPlatform $(ClPlatformTestKernels)

test: ClPlatformTest

clean: ClPlatformClean CommonClean SimCreateClean SimExecuteClean
	@rm -f lib/*.a

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
