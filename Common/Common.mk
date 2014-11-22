

LogsObj=      $(CommonObj)/logs.o
LogsObj+=     $(CommonObj)/Clock.o
LogsObj+=     $(CommonObj)/LogStream.o
LogsObj+=     $(CommonObj)/OpenPlConfiguration.o

filesToClean+= $(CommonObj)/*.o
filesToClean+= $(libLogs)

$(libLogs): $(LogsObj)
	@echo "\tLD\t"/Logs.a
	@mkdir -p $(dir $@) && ar rvs $@ $^ 2> /dev/null > /dev/null

$(CommonObj)/%.o: $(CommonSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@mkdir -p $(dir $@) && $(cpp) $< -o $@ $(AllInclude) $(cpp_flags)
