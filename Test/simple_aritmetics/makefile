
ProjectRoot=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

.PRECIOUS: MySim_add.cl

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@$(cpp) $^ -o $@ $(AllInclude) $(cpp_flags)

main: aritmetic.o main.o
	@echo "\tLN\t"$@
	@$(cpp) $^ $(allLibs) -o $@ $(OpenClLib) $(OpenGL) -lgtest -lgtest_main

clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.cl.2 *.clbin
