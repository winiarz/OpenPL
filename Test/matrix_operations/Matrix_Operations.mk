
TestBinaries+=  Bin/Test/MatrixOperations

MatrixOperations_Dir=Test/matrix_operations
MatrixOperations_ObjDir=Obj/$(MatrixOperations_Dir)

MatrixOperations_Obj+=$(MatrixOperations_ObjDir)/TestMatrixOperationsSim.o
MatrixOperations_Obj+=$(MatrixOperations_ObjDir)/TestMatrixOperationsMain.o

MatrixOperations_Includes+=$(MatrixOperations_Dir)/TestMatrixOperationsSim.hpp

MatrixOperationsTest: Bin/Test/MatrixOperations
	@echo "\tEXEC\tMatrixOperationsTest"
	@Bin/Test/MatrixOperations > /dev/null

$(MatrixOperations_ObjDir)/%.o: $(MatrixOperations_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(MatrixOperations_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/MatrixOperations: $(MatrixOperations_Obj) $(MatrixOperations_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(MatrixOperations_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(MatrixOperations_Obj) Bin/Test/MatrixOperations
