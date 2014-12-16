
TestBinaries+=  Bin/Test/NBody

NBody_Dir=Test/N_Body
NBody_ObjDir=Obj/$(NBody_Dir)

NBody_Obj+=$(NBody_ObjDir)/NBodyMain.o
NBody_Obj+=$(NBody_ObjDir)/NBodySim.o

NBody_Includes+= $(NBody_Dir)/NBodySim.hpp

$(NBody_ObjDir)/%.o: $(NBody_Dir)/%.cpp $(NBody_Includes) $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(NBody_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/NBody: $(NBody_Obj) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(NBody_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 
