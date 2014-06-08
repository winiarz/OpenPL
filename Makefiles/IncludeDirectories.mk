

#C++ include directories
ClPlatformInclude= -I$(ClPlatform)/Include -I$(ClPlatform)/Interface -I$(ClPlatform)/Mock
SimulationCreateInclude= -I$(SimulationCreate)/Include -I $(SimulationCreate)/Include/Types -I $(SimulationCreate)/Include/VecTypes -I $(SimulationCreate)/Include/Structures
SimulationExecuteInclude= -I$(SimulationExecute)/Include -I $(SimulationExecute)/Include/Types -I  $(SimulationExecute)/Include/VecTypes -I  $(SimulationExecute)/Include/Structures 
KernelLoaderInclude= -I$(KernelLoader)/Include -I$(KernelLoader)/Interface
SimulationInclude= -I$(Simulation)/Include $(SimulationCreateInclude) $(SimulationExecuteInclude)
CommonInclude= -I$(Common)/Include -I$(Common)/Interface -I$(Common)/Mock
InstructionProcessingInclude = -I$(InstructionProcessing)/Include -I$(InstructionProcessing)/Interface -I$(InstructionProcessing)/VariableTypes

IncludesForSimulationCreate=-I $(Simulation)/Include $(SimulationCreateInclude) 
IncludesForSimulationExecute=-I $(Simulation)/Include $(SimulationExecuteInclude) $(ClPlatformInclude)

#Mock includes
MockIncludes= -I$(ClPlatform)/Mock

AllInclude=$(ClPlatformInclude) $(SimulationInclude) $(CommonInclude) $(KernelLoaderInclude) $(MockIncludes) $(InstructionProcessingInclude)



#OpenCL include folders
ClInclude= -I $(ProjectRoot)/clinclude
