
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(SimExecute)/SimExecute.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute)

CompileTest: $(ClPlatform)/TestPlatform $(TestBin)/KernelLoaderGT $(ClPlatformTestKernels)

test: ClPlatformTest KernelLoaderTest

clean: ClPlatformClean CommonClean SimCreateClean SimExecuteClean KernelLoaderClean
	@rm -f lib/*.a
