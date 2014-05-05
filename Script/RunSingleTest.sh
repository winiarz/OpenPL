#!/bin/bash

endColor="\e[1;37m"

command=$1
logDir=$2
testName=$3

if [ $# -gt 3 ]; then
  currentNo=$4
  testCount=$5
  count="\t$currentNo/$testCount"
else
  count=""
fi

$command > $logDir/out 2> $logDir/err
result=$?


cp *.out $logDir > /dev/null 2> /dev/null
cp *.err $logDir > /dev/null 2> /dev/null


if [ $result == 0 ]; then
	color="\e[1;32m"
	verdict="PASS"
else
	color="\e[1;31m"
	verdict="FAIL"
fi

echo -en "                                                             \r"
echo -en "$count\t$color$verdict$endColor\t$testName\n"

exit $result
