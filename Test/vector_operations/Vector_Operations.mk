
TestBinaries+=  Bin/Test/VectorOperations

VectorOperations_Dir=Test/for_loop
VectorOperations_ObjDir=Obj/$(VectorOperations_Dir)

VectorOperations_Obj+=$(VectorOperations_ObjDir)/mysim.o
VectorOperations_Obj+=$(VectorOperations_ObjDir)/main.o

VectorOperations_Includes+=$(VectorOperations_Dir)/mysim.hpp

VectorOperationsTest: Bin/Test/VectorOperations
	@echo "\tEXEC\tVectorOperationsTest"
	@Bin/Test/VectorOperations > /dev/null

$(VectorOperations_ObjDir)/%.o: $(VectorOperations_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(VectorOperations_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/VectorOperations: $(VectorOperations_Obj) $(VectorOperations_Includes) compile
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(VectorOperations_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(VectorOperations_Obj) Bin/Test/VectorOperations
