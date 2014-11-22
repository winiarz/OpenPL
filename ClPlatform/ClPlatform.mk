
ClPlatformLibObj=    $(ClPlatformObj)/ClPlatform.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernel.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelFactory.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClMemory.o
ClPlatformLibObj+=   $(ClPlatformObj)/compile.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClParameterizedKernel.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClParameterizedKernelFromSource.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelPerformanceComparator.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClCalibrator.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelFromBinaryLoader.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelFromSourceLoader.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelSaver.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelCallStats.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClKernelManager.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClSelfCalibratingKernel.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClIncludePreprocessor.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClRandomFloatArrayGenerator.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClDataGeneratorComposite.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClDataGeneratorFromFileReader.o
ClPlatformLibObj+=   $(ClPlatformObj)/ClSelfCalibratingKernelFromFileReader.o
ClPlatformLibObj+=   $(ClPlatformObj)/OpenClCompiler.o
ClccObj=             $(ClPlatformObj)/clcc.o

ClPlatformTestObjs=  $(ClPlatformObj)/ClPlatformTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClMemoryTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClKernelTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClModuleTest.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClParameterizedKernelFromSourceTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClKernelPerformanceComparatorTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClCalibratorTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClDataGeneratorFileReadWriteTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClParameterizedKernelFromSourceTestSuite.o
ClPlatformTestObjs+= $(ClPlatformObj)/ClSelfCalibratingKernelTestSuite.o

ClPlatformTestKernels=  $(ClPlatform)/TestData/empty.clbin
ClPlatformTestKernels+= $(ClPlatform)/TestData/addition.clbin

filesToClean += $(ClPlatform)/TestPlatform
filesToClean += $(libClPlatform)
filesToClean += $(clcc)
filesToClean += $(ClPlatform)/TestData/*.clbin
filesToClean += $(ClPlatformObj)/*.o

$(clcc): $(ClPlatformLibObj) $(ClccObj) $(libLogs)
	@echo "\tLD\t"clcc
	@mkdir -p $(dir $@) && g++ $^ -o $@ $(OpenClLib) $(OpenGL)

ClPlatformTest: $(ClPlatform)/TestPlatform $(ClPlatformTestKernels)
	$(ClPlatform)/TestPlatform

$(libClPlatform): $(ClPlatformLibObj)
	@echo "\tLD\t"ClPlatform.a
	@mkdir -p $(dir $@) && ar rvs $@ $^ 2> /dev/null > /dev/null

$(ClPlatform)/TestPlatform: $(ClPlatformTestObjs) $(ClPlatformLibObj) $(libLogs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && g++ $^ -o $@ $(GTest) $(GMock) $(OpenClLib) $(OpenGL)

$(ClPlatformObj)/%.o: $(ClPlatformSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) &&  g++ $^ -o $@ $(AllInclude) $(cpp_flags)

$(ClPlatformObj)/%.o: $(ClPlatformTest)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && g++ $^ -o $@ $(AllInclude) $(cpp_flags)

%.clbin: %.cl $(clcc)
	@echo "\tCLCC\t"$*
	@mkdir -p $(dir $@) && $(clcc) $<
