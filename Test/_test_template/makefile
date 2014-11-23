
ProjectRoot=../../..
ClPlatform=../../../ClPlatform
Simulation=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@$(cpp) $^ -o $@ $(AllInclude) $(cpp_flags)

main: mysim.o main.o
	@echo "\tLN\t"$@
	@$(cpp) $^ $(allLibs) -o $@ $(OpenClLib) $(OpenGL)

clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.clbin
