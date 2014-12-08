
ProjectRoot=.

all: compile test

include config.mk

include $(ClPlatform)/ClPlatform.mk
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
include Test/for_loop/For_Loop.mk

compile: $(libClPlatform) $(libLogs) $(libSimCreate) $(libSimExecute) $(libInstructionProcessing)

CompileTest: $(TestBinaries)

test: ClPlatformTest InstructionProcessingTest CommonTest EmptySimulationTest DeclareMemoryTest CopyIntegersTest LocalVariablesTest SimpleAritmeticsTest ConstantsTest IfCommandTest

clean:
	@rm -f lib/*.a $(filesToClean)

cleanLogs:
	@rm -Rf logs/*
	@find . -name debug.txt -exec rm {} \;
