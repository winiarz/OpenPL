
TestBinaries+=  Bin/Test/Copy_Integers

CopyIntegers_Dir=Test/copy_integers
CopyIntegers_ObjDir=Obj/$(CopyIntegers_Dir)

CopyIntegers_Obj+=$(CopyIntegers_ObjDir)/TestCopyIntegersSim.o
CopyIntegers_Obj+=$(CopyIntegers_ObjDir)/TestCopyIntegersMain.o

CopyIntegers_Includes+=$(CopyIntegers_Dir)/TestCopyIntegersSim.hpp

CopyIntegersTest: Bin/Test/Copy_Integers
	@echo "\tEXEC\tCopyIntegersTest"
	@Bin/Test/Copy_Integers > /dev/null

$(CopyIntegers_ObjDir)/%.o: $(CopyIntegers_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(CopyIntegers_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Copy_Integers: $(CopyIntegers_Obj) $(CopyIntegers_Includes) $(allLibs)
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(CopyIntegers_Obj) $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL) 

filesToClean+=$(CopyIntegers_Obj) Bin/Test/Copy_Integers
