
TestBinaries+=  Bin/Test/VectorOperations

VectorOperations_Dir=Test/vector_operations
VectorOperations_ObjDir=Obj/$(VectorOperations_Dir)

VectorOperations_Obj+=$(VectorOperations_ObjDir)/vector_operations.o
VectorOperations_Obj+=$(VectorOperations_ObjDir)/main.o

VectorOperations_Includes+=$(VectorOperations_Dir)/vector_operations.hpp

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
