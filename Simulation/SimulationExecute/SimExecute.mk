
SimExecuteTypeGen=         $(SimExecuteScript)/seTypes.pl

SimExecuteLibObj=          $(SimExecuteObj)/seSimulationExecute.o
SimExecuteLibObj+=         $(SimExecuteObj)/seMaterialPointArray.o
SimExecuteLibObj+=         $(SimExecuteObj)/seLocalMaterialPoint.o
SimExecuteLibObj+=         $(SimExecuteObj)/seMatrix4x4Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/seLocalMatrix4x4.o
SimExecuteLibObj+=         $(SimExecuteObj)/seMatrix3x3Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/seLocalMatrix3x3.o

.PRECIOUS: $(SimExecuteAutogenIncludes) $(SimExecuteAutogenSources) $(SimExecuteObjFromAutogen)


$(libSimExecute): $(SimExecuteLibObj) $(SimExecuteObjFromAutogen)
	@echo "\tLD\t"SimulationExecute.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null

filesToClean+= $(SimExecuteAutogenIncludes) $(SimExecuteAutogenSources) $(SimExecuteObjFromAutogen) $(SimExecuteObj)/*.o $(libSimExecute)

#autogen includes
$(SimExecuteIncludeTypes)/seTypes.hpp: $(SimExecuteScript)/types.txt
	@$(SimExecuteTypeGen) gen_types $(SimExecute)

$(SimExecuteIncludeTypes)/se%Array.hpp: $(SimExecuteTemplates)/seArray.hpp
	@$(SimExecuteTypeGen) gen_array_include $(SimExecute) $*

$(SimExecuteIncludeVecTypes)/se%Array.hpp: $(SimExecuteTemplates)/seVectorArray.hpp
	@$(SimExecuteTypeGen) gen_vector_array_include $(SimExecute) $*

$(SimExecuteIncludeVecTypes)/seLocal%.hpp: $(SimExecuteTemplates)/seLocalVector.hpp
	@$(SimExecuteTypeGen) gen_local_vector_include $(SimExecute) $*


#autogen sources
$(SimExecuteSource)/VecTypes/se%Array.cpp: $(SimExecuteTemplates)/seVectorArray.cpp
	@$(SimExecuteTypeGen) gen_vector_array_source $(SimExecute) $*

$(SimExecuteSource)/Types/se%Array.cpp: $(SimExecuteTemplates)/seArray.cpp
	@$(SimExecuteTypeGen) gen_array_source $(SimExecute) $*

$(SimExecuteSource)/VecTypes/seLocal%.cpp: $(SimExecuteTemplates)/seLocalVector.cpp
	@$(SimExecuteTypeGen) gen_local_vector_source $(SimExecute) $*


$(SimExecuteObj)/%.o: $(SimExecuteSource)/%.cpp $(SimExecuteAutogenIncludes)
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)

$(SimExecuteObj)/%.o: $(SimExecuteSource)/Structures/%.cpp $(AllAutogenIncludes)
	@echo "\tCXX\t"$*.o
	@g++ $< -o $@ $(AllInclude) $(cpp_flags)
