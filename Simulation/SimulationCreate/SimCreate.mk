
SimCreateTypeGen=    $(SimCreateScript)/scTypes.pl

SimCreateLibObj=     $(SimCreateObj)/scSimulationCreate.o
SimCreateLibObj+=    $(SimCreateObj)/scVariable.o
SimCreateLibObj+=    $(SimCreateObj)/scArray.o
SimCreateLibObj+=    $(SimCreateObj)/scType.o
SimCreateLibObj+=    $(SimCreateObj)/scSimulation.o
SimCreateLibObj+=    $(SimCreateObj)/scNameGenerator.o
SimCreateLibObj+=    $(SimCreateObj)/scSizeOf.o
SimCreateLibObj+=    $(SimCreateObj)/scKernelToCreateSet.o
SimCreateLibObj+=    $(SimCreateObj)/scSimStepCreator.o
SimCreateLibObj+=    $(SimCreateObj)/scSingleKernelSimStep.o

SimCreateStructuresObj=  $(SimCreateObj)/scMaterialPointArray.o
SimCreateStructuresObj+= $(SimCreateObj)/scMaterialPoint.o

.PRECIOUS: $(SimCreateLibObj) $(SimCreateAutogenIncludes) $(SimCreateAutogenSources) 

filesToClean+= $(SimCreateObj)/*.o
filesToClean+= $(SimCreateAutogenSources) $(SimCreateAutogenIncludes) $(SimCreateObjFromAutogen)

$(libSimCreate): $(SimCreateLibObj) $(SimCreateObjFromAutogen) $(SimCreateStructuresObj)
	@echo "\tLD\t"SimulationCreate.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null

#autogen includes
$(SimCreateInclude)/Types/scTypes.hpp: $(SimCreate)/Script/types.txt
	@$(SimCreateTypeGen) gen_types $(SimCreate)

$(SimCreateInclude)/Types/sc%Array.hpp: $(SimCreateTemplates)/scArray.hpp
	@$(SimCreateTypeGen) gen_array_include $(SimCreate) $*

$(SimCreateInclude)/Types/sc%.hpp: $(SimCreateTemplates)/scType.hpp
	@$(SimCreateTypeGen) gen_type_include $(SimCreate) $*

$(SimCreateInclude)/VecTypes/sc%Array.hpp: $(SimCreateTemplates)/scArray.hpp
	@$(SimCreateTypeGen) gen_vector_array_include $(SimCreate) $*

$(SimCreateInclude)/VecTypes/sc%.hpp: $(SimCreateTemplates)/scVector.hpp
	@$(SimCreateTypeGen) gen_vector_include $(SimCreate) $*

#autogen sources
$(SimCreateSource)/Types/sc%Array.cpp: $(SimCreateTemplates)/scArray.cpp
	@$(SimCreateTypeGen) gen_array_source $(SimCreate) $*

$(SimCreateSource)/Types/sc%.cpp: $(SimCreateTemplates)/scType.cpp
	@$(SimCreateTypeGen) gen_type_source  $(SimCreate) $*

$(SimCreateSource)/VecTypes/sc%Array.cpp: $(SimCreateTemplates)/scVectorArray.cpp
	@$(SimCreateTypeGen) gen_vector_array_source $(SimCreate) $*

$(SimCreateSource)/VecTypes/sc%.cpp: $(SimCreateTemplates)/scVector.cpp
	@$(SimCreateTypeGen) gen_vector_source $(SimCreate) $*

$(SimCreateObj)/%.o: $(SimCreateSource)/%.cpp $(AllAutogenIncludes)
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)

$(SimCreateObj)/%.o: $(SimCreateSource)/Structures/%.cpp $(AllAutogenIncludes)
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)

