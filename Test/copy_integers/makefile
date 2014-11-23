
ProjectRoot=../..

clcc=$(ProjectRoot)/clcc

include $(ProjectRoot)/config.mk

.PRECIOUS: MySim_copy.cl

all: main

%.o: %.cpp
	@echo "\tCXX\t"$@
	@$(cpp) $^ -o $@ $(AllInclude) $(cpp_flags)

main: copy_integers.o main.o
	@echo "\tLN\t"$@
	@$(cpp) $^ $(allLibs) -o $@ $(OpenClLib) -lgtest -lgtest_main $(OpenGL)

%.c: %.cpp
	@echo "\tCXX\t"$@
	@$(cpp) $^ -E -o $@ $(AllInclude) $(cpp_flags)


clean:
	@echo "\tRM\t"
	@rm -f kernel_create main *.o *.cl *.clbin *.err *.out
