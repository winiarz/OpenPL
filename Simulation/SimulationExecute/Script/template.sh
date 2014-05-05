#!/bin/bash

function replace {
in=$1
temp=$1.temp
sed "s/\$$2/$3/g" < $in > $temp
rm $in
mv $temp $in
}

fileIn=$1;  shift
fileOut=$1; shift
cp $fileIn $fileOut
replacementsCount=0

while [ $# -gt 0 ]
do
  if [ $1 == "-r" ]; then
    shift
    replace $fileOut $1 $2
    shift
    replacementsCount=$(( $replacementsCount + 1 ))
  fi
  shift
done
