
TestBinaries+=  Bin/Test/Declare_Memory

DeclareMemory_Dir=Test/declare_memory
DeclareMemory_ObjDir=Obj/$(DeclareMemory_Dir)

DeclareMemory_Obj+=$(DeclareMemory_ObjDir)/declare_memory.o
DeclareMemory_Obj+=$(DeclareMemory_ObjDir)/main.o

DeclareMemory_Includes+=$(DeclareMemory_Dir)/declare_memory.hpp

DeclareMemoryTest: Bin/Test/Declare_Memory
	@echo "\tEXEC\tDeclareMemoryTest"
	@Bin/Test/Declare_Memory > /dev/null

$(DeclareMemory_ObjDir)/%.o: $(DeclareMemory_Dir)/%.cpp $(allLibs)
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ -I $(DeclareMemory_Dir) $(AllInclude) $(cpp_flags)

Bin/Test/Declare_Memory: $(DeclareMemory_Obj) $(DeclareMemory_Includes) compile
	@echo "\tLD\t"$@
	@mkdir -p $(dir $@) && $(cpp) $(DeclareMemory_Obj) $(allLibs) -o $@ $(OpenClLib) $(OpenGL)

filesToClean+=$(DeclareMemory_Obj) Bin/Test/Declare_Memory
