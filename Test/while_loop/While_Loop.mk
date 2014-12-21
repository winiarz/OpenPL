
TestBinaries+=  Bin/Test/WhileLoop

WhileLoop_Dir=Test/while_loop
WhileLoop_ObjDir=Obj/$(WhileLoop_Dir)

WhileLoop_Obj+=$(WhileLoop_ObjDir)/TestWhileLoopSim.o
WhileLoop_Obj+=$(WhileLoop_ObjDir)/TestWhileLoopMain.o

WhileLoop_Includes+=$(WhileLoop_Dir)/TestWhileLoopSim.hpp

WhileLoopTest: Bin/Test/WhileLoop
	@echo "\tEXEC\tWhileLoopTest"
	@Bin/Test/WhileLoop > /dev/null

$(WhileLoop_ObjDir)/%.o: $(WhileLoop_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(WhileLoop_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/WhileLoop: $(WhileLoop_Obj) $(WhileLoop_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(WhileLoop_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(WhileLoop_Obj) Bin/Test/WhileLoop
