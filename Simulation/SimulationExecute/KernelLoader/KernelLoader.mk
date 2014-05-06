

KernelLoaderLibObj=         $(KernelLoaderObj)/KernelLoader.o

KernelLoaderTestObj=        $(KernelLoaderObj)/KernelLoaderTestSuite.o
KernelLoaderTestObj+=       $(KernelLoaderObj)/KernelLoader.o

KernelLoaderClean:
	@rm -f Obj/*.o $(TestBin)/KernelLoaderGT

KernelLoaderTest: $(TestBin)/KernelLoaderGT
	$(TestBin)/KernelLoaderGT

$(TestBin)/KernelLoaderGT: $(KernelLoaderTestObj) $(libClPlatform) $(libLogs)
	@echo "\tLD\tKernelLoaderGT"
	@g++ $^ $(OpenClLib) $(GMock) $(GTest) -o $@

$(libKernelLoader): $(KernelLoaderLibObj)
	@echo "\tLD\t"SimulationExecute.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null

$(KernelLoaderObj)/%.o: $(KernelLoaderTestSource)/%.cpp $(AllAutogenIncludes)
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)

$(KernelLoaderObj)/%.o: $(KernelLoaderSource)/%.cpp $(AllAutogenIncludes)
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)
