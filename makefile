CppCompiler=g++
ClCompiler=bin/clcc
includePath=include
LibOpenCL=-lOpenCL
all: lib/clSystem.a $(ClCompiler)

clean:
	rm obj/clSystem/*.o

$(ClCompiler): obj/clcc.o lib/clSystem.a
	$(CppCompiler) obj/clcc.o lib/clSystem.a -o $(ClCompiler) $(LibOpenCL)

lib/clSystem.a: obj/clSystem/system.o obj/clSystem/kernel.o obj/clSystem/memory.o obj/clSystem/save.o obj/clSystem/open.o
	ar rvs lib/clSystem.a obj/clSystem/system.o obj/clSystem/kernel.o obj/clSystem/memory.o obj/clSystem/save.o obj/clSystem/open.o

obj/clSystem/system.o: include/clSystem/system.h src/clSystem/system.cpp
	$(CppCompiler) src/clSystem/system.cpp -c -o obj/clSystem/system.o -I $(includePath)

obj/clSystem/kernel.o: include/clSystem/system.h include/clSystem/kernel.h include/clSystem/memory.h src/clSystem/kernel.cpp
	$(CppCompiler) src/clSystem/kernel.cpp -c -o obj/clSystem/kernel.o -I $(includePath)

obj/clSystem/memory.o: include/clSystem/system.h include/clSystem/memory.h src/clSystem/memory.cpp
	$(CppCompiler) src/clSystem/memory.cpp -c -o obj/clSystem/memory.o -I $(includePath)

obj/clSystem/open.o: include/clSystem/system.h src/clSystem/open.cpp
	$(CppCompiler) src/clSystem/open.cpp -c -o obj/clSystem/open.o -I $(includePath)

obj/clSystem/save.o: include/clSystem/system.h src/clSystem/save.cpp
	$(CppCompiler) src/clSystem/save.cpp -c -o obj/clSystem/save.o -I $(includePath)

obj/clcc.o: include/clSystem/system.h include/clSystem/kernel.h include/clSystem/memory.h src/clcc.cpp
	$(CppCompiler) src/clcc.cpp -c -o obj/clcc.o -I $(includePath)
