
ClPlatformLibObj=    $(ClPlatformObj)/ClPlatform.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernel.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelFactory.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClMemory.o
ClPlatformLibObj+=   $(ClPlatformObj)/open.o
ClPlatformLibObj+=   $(ClPlatformObj)/save.o
ClPlatformLibObj+=   $(ClPlatformObj)/compile.o
ClPlatformLibObj+=   $(ClPlatformObj)/include.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClParameterizedKernel.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClParameterizedKernelFromSource.o

ClccObj=             $(ClPlatformObj)/clcc.o

ClPlatformTestObjs=  $(ClPlatformObj)/ClPlatformTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClMemoryTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClKernelTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClModuleTest.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClParameterizedKernelFromSourceTestSuite.o

ClPlatformTestKernels=  $(ClPlatform)/TestData/empty.clbin
ClPlatformTestKernels+= $(ClPlatform)/TestData/addition.clbin

$(clcc): $(ClPlatformLibObj) $(ClccObj)
	@echo "\tLD\t"clcc
	@g++ $^ -o $@ $(OpenClLib) $(OpenGL)

ClPlatformTest: $(ClPlatform)/TestPlatform $(ClPlatformTestKernels)
	@cd $(ClPlatform); ./TestPlatform

ClPlatformClean:
	@rm -f $(ClPlatform)/TestPlatform $(ClPlatformObj)/*.o $(libClPlatform) $(clcc) $(ClPlatform)/TestData/*.clbin

$(libClPlatform): $(ClPlatformLibObj)
	@echo "\tLD\t"ClPlatform.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null

$(ClPlatform)/TestPlatform: $(ClPlatformTestObjs) $(ClPlatformLibObj)
	@echo "\tLD\t"$@
	@g++ $^ -o $@ $(GTest) $(GMock) $(OpenClLib) $(OpenGL)

$(ClPlatformObj)/%.o: $(ClPlatformSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $^ -o $@ $(ClPlatformInclude) $(cpp_flags)

$(ClPlatformObj)/%.o: $(ClPlatformTest)/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $^ -o $@ $(ClPlatformInclude) $(cpp_flags)

%.clbin: %.cl $(clcc)
	@echo "\tCLCC\t"$*
	@$(clcc) $<
