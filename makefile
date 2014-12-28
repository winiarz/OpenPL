
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
include Clcc/Clcc.mk
include $(Common)/Common.mk
include $(SimCreate)/SimCreate.mk
include $(InstructionProcessing)/Makefiles/InstructionProcessing.mk
include $(SimExecute)/SimExecute.mk

include Test/empty_sim/Empty_Simulation.mk
include Test/declare_memory/Declare_Memory.mk
include Test/copy_integers/Copy_Integers.mk
include Test/local_variables/Local_Variables.mk
include Test/simple_aritmetics/SimpleAritmetics.mk
include Test/constants/Constants.mk
include Test/if_command/If_Command.mk
include Test/while_loop/While_Loop.mk
include Test/for_loop/For_Loop.mk
include Test/vector_operations/Vector_Operations.mk
include Test/matrix_operations/Matrix_Operations.mk
include Test/material_point/Material_Point.mk
include Test/constant_force/Constant_Force.mk
include Test/N_Body/N_Body.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute) $(libInstructionProcessing)

CompileTest: $(TestBinaries)

test: ClPlatformTest InstructionProcessingTest CommonTest EmptySimulationTest DeclareMemoryTest CopyIntegersTest LocalVariablesTest SimpleAritmeticsTest ConstantsTest IfCommandTest WhileLoopTest ForLoopTest VectorOperationsTest MatrixOperationsTest MaterialPointTest

clean:
	@rm -Rf Obj/* lib/*.a $(filesToClean)

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
