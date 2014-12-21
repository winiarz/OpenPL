
TestBinaries+=  Bin/Test/Empty_Simulation

EmptySim_Dir=Test/empty_sim
EmptySim_ObjDir=Obj/$(EmptySim_Dir)

EmptySim_Obj+=$(EmptySim_ObjDir)/TestEmptySimSim.o
EmptySim_Obj+=$(EmptySim_ObjDir)/TestEmptySimMain.o

EmptySim_Includes+=$(EmptySim_Dir)/TestEmptySimSim.hpp

EmptySimulationTest: Bin/Test/Empty_Simulation
	@echo "\tEXEC\tEmptySimulationTest"
	@Bin/Test/Empty_Simulation > /dev/null

$(EmptySim_ObjDir)/%.o: $(EmptySim_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(EmptySim_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Empty_Simulation: $(EmptySim_Obj) $(EmptySim_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(EmptySim_Obj) $(allLibs) -o $@ $(OpenClLib) $(OpenGL)

filesToClean+=$(EmptySim_Obj) Bin/Test/Empty_Simulation
