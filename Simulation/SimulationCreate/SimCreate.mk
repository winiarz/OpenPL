
SimCreateTypeGen=    $(SimCreateScript)/scTypes.pl

SimCreateLibObj=     $(SimCreateObj)/scSimulationCreate.o
SimCreateLibObj+=    $(SimCreateObj)/scVariable.o
SimCreateLibObj+=    $(SimCreateObj)/scSimulation.o
SimCreateLibObj+=    $(SimCreateObj)/scNameGenerator.o
SimCreateLibObj+=    $(SimCreateObj)/scSizeOf.o
SimCreateLibObj+=    $(SimCreateObj)/scKernelToCreateSet.o
SimCreateLibObj+=    $(SimCreateObj)/scSimStepCreator.o
SimCreateLibObj+=    $(SimCreateObj)/scSingleKernelSimStep.o

.PRECIOUS: $(SimCreateLibObj) $(SimCreateAutogenIncludes) $(SimCreateAutogenSources) 

filesToClean+= $(SimCreateObj)/*.o

$(libSimCreate): $(SimCreateLibObj) $(SimCreateObjFromAutogen)
	@echo "\tLD\t"SimulationCreate.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null


$(SimCreateObj)/%.o: $(SimCreateSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)

$(SimCreateObj)/%.o: $(SimCreateSource)/Structures/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)

