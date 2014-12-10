
TestBinaries+=  Bin/Test/Simple_Aritmetics

SimpleAritmetics_Dir=Test/simple_aritmetics
SimpleAritmetics_ObjDir=Obj/$(SimpleAritmetics_Dir)

SimpleAritmetics_Obj+=$(SimpleAritmetics_ObjDir)/aritmetic.o
SimpleAritmetics_Obj+=$(SimpleAritmetics_ObjDir)/main.o

SimpleAritmetics_Includes+=$(SimpleAritmetics_Dir)/aritmetic.hpp

SimpleAritmeticsTest: Bin/Test/Simple_Aritmetics
	@echo "\tEXEC\tSimpleAritmeticsTest"
	@Bin/Test/Simple_Aritmetics > /dev/null

$(SimpleAritmetics_ObjDir)/%.o: $(SimpleAritmetics_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(SimpleAritmetics_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Simple_Aritmetics: $(SimpleAritmetics_Obj) $(SimpleAritmetics_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(SimpleAritmetics_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(SimpleAritmetics_Obj) Bin/Test/Simple_Aritmetics
