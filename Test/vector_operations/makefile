
ProjectRoot=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

.PRECIOUS: $(typesSourceFiles) $(typesIncludeFiles)

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@g++ $^ -o $@ $(AllInclude) -c

main: vector_operations.o main.o
	@echo "\tLN\t"$@
	@g++ $^ $(allLibs) -o $@ $(OpenClLib) $(OpenGL) -lgtest -lgtest_main

clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.clbin
