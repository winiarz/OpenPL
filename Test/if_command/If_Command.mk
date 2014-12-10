
TestBinaries+=  Bin/Test/If_Command

If_Command_Dir=Test/if_command
If_Command_ObjDir=Obj/$(If_Command_Dir)

If_Command_Obj+=$(If_Command_ObjDir)/mysim.o
If_Command_Obj+=$(If_Command_ObjDir)/main.o

If_Command_Includes+=$(If_Command_Dir)/mysim.hpp

IfCommandTest: Bin/Test/If_Command
	@echo "\tEXEC\tIf_CommandTest"
	@Bin/Test/If_Command > /dev/null

$(If_Command_ObjDir)/%.o: $(If_Command_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(If_Command_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/If_Command: $(If_Command_Obj) $(If_Command_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(If_Command_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(If_Command_Obj) Bin/Test/If_Command
