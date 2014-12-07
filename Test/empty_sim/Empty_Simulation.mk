
TestBinaries+=  Bin/Test/Empty_Simulation

EmptySim_Dir=Test/empty_sim
EmptySim_ObjDir=Obj/$(EmptySim_Dir)

EmptySim_Obj+=$(EmptySim_ObjDir)/empty_sim.o
EmptySim_Obj+=$(EmptySim_ObjDir)/main.o

EmptySim_Includes+=$(EmptySim_Dir)/empty_sim.hpp

EmptySimulationTest: Bin/Test/Empty_Simulation
	@echo "\tEXEC\tEmptySimulationTest"
	@Bin/Test/Empty_Simulation > /dev/null

$(EmptySim_ObjDir)/%.o: $(EmptySim_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(EmptySim_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Empty_Simulation: $(EmptySim_Obj) $(EmptySim_Includes) compile
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(EmptySim_Obj) $(allLibs) -o $@ $(OpenClLib) $(OpenGL)

filesToClean+=$(EmptySim_Obj) Bin/Test/Empty_Simulation
