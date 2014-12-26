
SimExecuteLibObj+=         $(SimExecuteObj)/seMaterialPointArray.o
SimExecuteLibObj+=         $(SimExecuteObj)/seLocalMaterialPoint.o
SimExecuteLibObj+=         $(SimExecuteObj)/seMatrix4x4Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/seLocalMatrix4x4.o
SimExecuteLibObj+=         $(SimExecuteObj)/seMatrix3x3Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/seLocalMatrix3x3.o
SimExecuteLibObj+=         $(SimExecuteObj)/Types/seIntArray.o
SimExecuteLibObj+=         $(SimExecuteObj)/VecTypes/seInt3Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/VecTypes/seLocalInt3.o
SimExecuteLibObj+=         $(SimExecuteObj)/Types/seFloatArray.o
SimExecuteLibObj+=         $(SimExecuteObj)/VecTypes/seFloat3Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/VecTypes/seFloat4Array.o
SimExecuteLibObj+=         $(SimExecuteObj)/VecTypes/seLocalFloat3.o
SimExecuteLibObj+=         $(SimExecuteObj)/VecTypes/seLocalFloat4.o

$(libSimExecute): $(SimExecuteLibObj)
	@echo "\tLD\t"SimulationExecute.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null

filesToClean+=$(SimExecuteObj)/*.o $(libSimExecute)

$(SimExecuteObj)/%.o: $(SimExecuteSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ $(AllInclude) $(cpp_flags)

$(SimExecuteObj)/%.o: $(SimExecuteSource)/Structures/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ $(AllInclude) $(cpp_flags)
