
InstructionProcessingObj=     $(InstructionProcessing)/Obj
InstructionProcessingSource=  $(InstructionProcessing)/Source
InstructionProcessingTest=    $(InstructionProcessing)/Test

InstructionProcessingObjs+=     $(InstructionProcessingObj)/SingleInstruction.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/InstructionBlock.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Type.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Variable.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Function.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/Kernel.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/InstructionRecorder.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/ForLoop.o
InstructionProcessingObjs+=     $(InstructionProcessingObj)/WhileLoop.o


InstructionProcessingTestObjs+= $(InstructionProcessingObj)/FunctionTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/KernelTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/InstructionRecorderTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/ForLoopTestSuite.o
InstructionProcessingTestObjs+= $(InstructionProcessingObj)/WhileLoopTestSuite.o

$(InstructionProcessingObj)/%.o: $(InstructionProcessingSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $^ -o $@ $(AllInclude) $(cpp_flags)

$(InstructionProcessingObj)/%.o: $(InstructionProcessingTest)/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $^ -o $@ $(AllInclude) $(cpp_flags)

$(libInstructionProcessing): $(InstructionProcessingObjs)
	@echo "\tLD\t"libInstructionProcessing
	@ar rvs $@ $^ 2> /dev/null > /dev/null

Bin/InstructionProcessingTS: $(InstructionProcessingTestObjs) $(allLibs)
	@echo "\tLD\t"$@
	@g++ $^ -o $@ $(GTest) $(GMock) $(OpenClLib) $(OpenGL)
