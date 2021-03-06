#!/bin/bash

failColor="\e[1;31m"
passColor="\e[1;32m"
endColor="\e[1;37m"

runSingleTest=`pwd`/Script/RunSingleTest.sh
TestList=Test/regresion.list
logMainDir=`pwd`/logs
date=`date "+%H:%M_%d-%b-%Y"`
logDir="$logMainDir/$date"
mkdir -p $logDir

Script/build.sh > $logDir/compile 2> $logDir/compile.err

compileResult=$?
if [ $compileResult != 0 ]; then
    echo -en "$failColor COMPILATION FAILED $endColor \n"
    exit 1
fi

test_count=`wc -l < $TestList`
test_number=1
passed=0
failed=0

function testcase {
  command="$1"
  testname="$2"

  logDirForTestcase="$logDir/$testname"
  mkdir -p $logDirForTestcase

  echo -en "\t$test_number/$test_count $testname\r"
  cp openpl.config $dir 2> /dev/null
  pushd "$dir" > /dev/null
  $runSingleTest $command $logDirForTestcase $testname $test_number $test_count

  result=$?
  if [ $result == 0 ]; then
    passed=$(( $passed + 1))
    $runSingleTest "$command clean" $logDirForTestcase $testname $test_number $test_count > /dev/null
  else
    failed=$(( $failed + 1))
  fi
  popd > /dev/null
}




while read line
do
  testcase $line
  test_number=$(( $test_number + 1 ))
done < $TestList

if [ $passed -gt 0 ]; then
  echo -en "\t$passColor PASS  $passed/$test_count$endColor\t"
fi

if [ $failed -gt 0 ]; then
  echo -en "\t$failColor FAIL  $failed/$test_count$endColor"
fi
echo -en "\n"
