
TestBinaries+=  Bin/Test/WhileLoop

WhileLoop_Dir=Test/for_loop
WhileLoop_ObjDir=Obj/$(WhileLoop_Dir)

WhileLoop_Obj+=$(WhileLoop_ObjDir)/mysim.o
WhileLoop_Obj+=$(WhileLoop_ObjDir)/main.o

WhileLoop_Includes+=$(WhileLoop_Dir)/mysim.hpp

WhileLoopTest: Bin/Test/WhileLoop
	@echo "\tEXEC\tWhileLoopTest"
	@Bin/Test/WhileLoop > /dev/null

$(WhileLoop_ObjDir)/%.o: $(WhileLoop_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(WhileLoop_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/WhileLoop: $(WhileLoop_Obj) $(WhileLoop_Includes) compile
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(WhileLoop_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(WhileLoop_Obj) Bin/Test/WhileLoop
