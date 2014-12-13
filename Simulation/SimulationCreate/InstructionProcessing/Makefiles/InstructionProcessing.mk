
TestBinaries+=  Bin/Test/InstructionProcessingTS

InstructionProcessingObj=     $(Obj)/Simulation/SimulationCreate/InstructionProcessing
InstructionProcessingSource=  $(InstructionProcessing)/Source
InstructionProcessingTest=    $(InstructionProcessing)/Test

InstructionProcessingObjs+=     $(InstructionProcessingObj)/SingleInstruction.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/InstructionBlock.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Variable.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/IVariable.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Function.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Kernel.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/InstructionRecorder.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/ForLoop.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/WhileLoop.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/IfInstruction.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Int.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/NumericVariable.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/VectorVariable.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/MatrixVariable.o

InstructionProcessingTestObjs+= $(InstructionProcessingObj)/FunctionTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/KernelTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/InstructionRecorderTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/ForLoopTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/WhileLoopTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/IfInstructionTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/GlobalArrayTestSuite.o

InstructionProcessingTest: Bin/Test/InstructionProcessingTS
	@echo "\tEXEC\tInstructionProcessingTest"
	@Bin/Test/InstructionProcessingTS > /dev/null

$(InstructionProcessingObj)/%.o: $(InstructionProcessingSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $^ -o $@ $(AllInclude) $(cpp_flags)

$(InstructionProcessingObj)/%.o: $(InstructionProcessingTest)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $^ -o $@ $(AllInclude) $(cpp_flags)

$(libInstructionProcessing): $(InstructionProcessingObjs)
	@echo "\tLD\t"libInstructionProcessing
	@mkdir -p $(dir $@) && ar rvs $@ $^ 2> /dev/null > /dev/null

Bin/Test/InstructionProcessingTS: $(InstructionProcessingTestObjs) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $^ -o $@ $(GTest) $(GMock) $(OpenClLib) $(OpenGL)

filesToClean+=     Bin/Test/InstructionProcessingTS
filesToClean+=     $(InstructionProcessingObj)/*.o
filesToClean+=     $(libInstructionProcessing)
