
TestBinaries+=  Bin/Test/ForLoop

ForLoop_Dir=Test/for_loop
ForLoop_ObjDir=Obj/$(ForLoop_Dir)

ForLoop_Obj+=$(ForLoop_ObjDir)/TestForLoopSim.o
ForLoop_Obj+=$(ForLoop_ObjDir)/TestForLoopMain.o

ForLoop_Includes+=$(ForLoop_Dir)/TestForLoopSim.hpp

ForLoopTest: Bin/Test/ForLoop
	@echo "\tEXEC\tForLoopTest"
	@Bin/Test/ForLoop > /dev/null

$(ForLoop_ObjDir)/%.o: $(ForLoop_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(ForLoop_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/ForLoop: $(ForLoop_Obj) $(ForLoop_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(ForLoop_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(ForLoop_Obj) Bin/Test/ForLoop
