
InstructionProcessingObj=     $(InstructionProcessing)/Obj
InstructionProcessingSource=  $(InstructionProcessing)/Source

InstructionProcessingObjs+=     $(InstructionProcessingObj)/SingleInstruction.o

$(InstructionProcessingObj)/%.o: $(InstructionProcessingSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@g++ $^ -o $@ $(AllInclude) $(cpp_flags)

$(libInstructionProcessing): $(InstructionProcessingObjs)
	@echo "\tLD\t"libInstructionProcessing
	@ar rvs $@ $^ 2> /dev/null > /dev/null
