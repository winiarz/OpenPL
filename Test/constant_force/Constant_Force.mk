
TestBinaries+=  Bin/Test/ConstantForce

ConstantForce_Dir=Test/constant_force
ConstantForce_ObjDir=Obj/$(ConstantForce_Dir)

ConstantForce_Obj+= $(ConstantForce_ObjDir)/TestConstantForceMain.o
ConstantForce_Obj+= $(ConstantForce_ObjDir)/TestConstantForceSim.o

ConstantForce_Includes+= $(ConstantForce_Dir)/TestConstantForceSim.hpp

$(ConstantForce_ObjDir)/%.o: $(ConstantForce_Dir)/%.cpp $(ConstantForce_Includes) $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(ConstantForce_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/ConstantForce: $(ConstantForce_Obj) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(ConstantForce_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+= Bin/Test/ConstantForce $(ConstantForce_Obj)
