
TestBinaries+=  Bin/Test/Local_Variables

LocalVariables_Dir=Test/local_variables
LocalVariables_ObjDir=Obj/$(LocalVariables_Dir)

LocalVariables_Obj+=$(LocalVariables_ObjDir)/TestLocalVariablesSim.o
LocalVariables_Obj+=$(LocalVariables_ObjDir)/TestLocalVariablesMain.o

LocalVariables_Includes+=$(LocalVariables_Dir)/TestLocalVariablesSim.hpp

LocalVariablesTest: Bin/Test/Local_Variables
	@echo "\tEXEC\tLocalVariablesTest"
	@Bin/Test/Local_Variables > /dev/null

$(LocalVariables_ObjDir)/%.o: $(LocalVariables_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(LocalVariables_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Local_Variables: $(LocalVariables_Obj) $(LocalVariables_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(LocalVariables_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(LocalVariables_Obj) Bin/Test/Local_Variables
