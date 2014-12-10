
TestBinaries+=  Bin/Test/MaterialPoint

MaterialPoint_Dir=Test/for_loop
MaterialPoint_ObjDir=Obj/$(MaterialPoint_Dir)

MaterialPoint_Obj+=$(MaterialPoint_ObjDir)/mysim.o
MaterialPoint_Obj+=$(MaterialPoint_ObjDir)/main.o

MaterialPoint_Includes+=$(MaterialPoint_Dir)/mysim.hpp

MaterialPointTest: Bin/Test/MaterialPoint
	@echo "\tEXEC\tMaterialPointTest"
	@Bin/Test/MaterialPoint > /dev/null

$(MaterialPoint_ObjDir)/%.o: $(MaterialPoint_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(MaterialPoint_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/MaterialPoint: $(MaterialPoint_Obj) $(MaterialPoint_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(MaterialPoint_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(MaterialPoint_Obj) Bin/Test/MaterialPoint
