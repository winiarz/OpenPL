

LogsObj=      $(CommonObj)/logs.o
LogsObj+=     $(CommonObj)/Clock.o
LogsObj+=     $(CommonObj)/NullStream.o

CommonClean:
	@rm -f $(CommonObj)/*.o $(libLogs)

$(libLogs): $(LogsObj)
	@echo "\tLD\t"/Logs.a
	@ar rvs $@ $^ 2> /dev/null > /dev/null

$(CommonObj)/%.o: $(CommonSource)/%.cpp
	@echo "\tCXX\t"$*.o
	@$(cpp) $< -o $@ $(AllInclude) $(cpp_flags)