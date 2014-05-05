
ProjectRoot=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@g++ $^ -o $@ $(AllInclude) $(cpp_flags)

main: mysim.o main.o 
	@echo "\tLN\t"$@
	@g++ $^ $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL)

clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.clbin
