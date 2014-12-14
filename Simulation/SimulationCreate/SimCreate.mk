
SimCreateTypeGen=    $(SimCreateScript)/scTypes.pl

SimCreateLibObj+=    $(SimCreateObj)/scNameGenerator.o
SimCreateLibObj+=    $(SimCreateObj)/scSizeOf.o
SimCreateLibObj+=    $(SimCreateObj)/scSimStepCreator.o
SimCreateLibObj+=    $(SimCreateObj)/scSingleKernelSimStep.o

.PRECIOUS: $(SimCreateLibObj) $(SimCreateAutogenIncludes) $(SimCreateAutogenSources) 

filesToClean+= $(SimCreateObj)/*.o

$(libSimCreate): $(SimCreateLibObj) $(SimCreateObjFromAutogen)
	@echo "\tLD\t"SimulationCreate.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null


$(SimCreateObj)/%.o: $(SimCreateSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ $(AllInclude) $(cpp_flags)

$(SimCreateObj)/%.o: $(SimCreateSource)/Structures/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ $(AllInclude) $(cpp_flags)

