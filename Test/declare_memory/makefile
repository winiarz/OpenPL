
ProjectRoot=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@g++ $^ -o $@ $(AllInclude) $(cpp_flags)

main: declare_memory.o main.o $(allLibs)
	@echo "\tLN\t"$@
	@g++ $^ $(allLibs) -o $@ $(OpenClLib) $(OpenGL)

clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.clbin
