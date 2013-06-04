CppCompiler=g++
ClCompiler=bin/clcc
includePath=include

all: clSystem

clSystem: obj/clSystem/system.o obj/clSystem/kernel.o obj/clSystem/memory.o

clean:
	rm obj/clSystem/*.o

obj/clSystem/system.o: include/clSystem/system.h src/clSystem/system.cpp
	$(CppCompiler) src/clSystem/system.cpp -c -o obj/clSystem/system.o -I $(includePath)

obj/clSystem/kernel.o: include/clSystem/system.h include/clSystem/kernel.h include/clSystem/memory.h src/clSystem/kernel.cpp
	$(CppCompiler) src/clSystem/kernel.cpp -c -o obj/clSystem/kernel.o -I $(includePath)

obj/clSystem/memory.o: include/clSystem/system.h include/clSystem/memory.h src/clSystem/memory.cpp
	$(CppCompiler) src/clSystem/memory.cpp -c -o obj/clSystem/memory.o -I $(includePath)