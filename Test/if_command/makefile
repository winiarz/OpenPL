
ProjectRoot=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@g++ $^ -o $@ $(AllInclude) $(cpp_flags)

main: mysim.o main.o $(allLibs) 
	@echo "\tLN\t"$@
	@g++ $^ -o $@ $(OpenClLib) $(OpenGL) -lgtest -lgtest_main

clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.clbin
	
