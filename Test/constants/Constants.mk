
TestBinaries+=  Bin/Test/Constants

Constants_Dir=Test/constants
Constants_ObjDir=Obj/$(Constants_Dir)

Constants_Obj+=$(Constants_ObjDir)/TestConstantsSim.o
Constants_Obj+=$(Constants_ObjDir)/TestConstantsMain.o

Constants_Includes+=$(Constants_Dir)/TestConstantsSim.hpp

ConstantsTest: Bin/Test/Constants
	@echo "\tEXEC\tConstantsTest"
	@Bin/Test/Constants > /dev/null

$(Constants_ObjDir)/%.o: $(Constants_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(Constants_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Constants: $(Constants_Obj) $(Constants_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(Constants_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(Constants_Obj) Bin/Test/Constants
