
TestBinaries+=  Bin/Test/VectorOperations

VectorOperations_Dir=Test/vector_operations
VectorOperations_ObjDir=Obj/$(VectorOperations_Dir)

VectorOperations_Obj+=$(VectorOperations_ObjDir)/TestVectorOperationsSim.o
VectorOperations_Obj+=$(VectorOperations_ObjDir)/TestVectorOperationsMain.o

VectorOperations_Includes+=$(VectorOperations_Dir)/TestVectorOperationsSim.hpp

VectorOperationsTest: Bin/Test/VectorOperations
	@echo "\tEXEC\tVectorOperationsTest"
	@Bin/Test/VectorOperations > /dev/null

$(VectorOperations_ObjDir)/%.o: $(VectorOperations_Dir)/%.cpp $(VectorOperations_Includes) $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(VectorOperations_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/VectorOperations: $(VectorOperations_Obj) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(VectorOperations_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(VectorOperations_Obj) Bin/Test/VectorOperations
