
ClccObj=$(Obj)/Clcc
ClccSrc=Clcc/Source

ClccObjs += $(ClccObj)/clcc.o
ClccObjs += $(ClccObj)/compile.o

$(clcc): $(ClccObjs) $(libClPlatform) $(libLogs)
	@echo "\tLD\t"clcc
	@mkdir -p $(dir $@) && $(cpp) $^ -o $@ $(OpenClLib) $(OpenGL) 

$(ClccObj)/%.o: $(ClccSrc)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $^ -o $@ $(AllInclude) $(cpp_flags)
