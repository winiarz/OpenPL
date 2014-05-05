#!/bin/bash


if [ "$1" == "clean" ]; then
  make clean > /dev/null 2> /dev/null
  rm -f  make.out make.err main.out main.err
else
  make clean > /dev/null 2> /dev/null
  rm -f  make.out make.err main.out main.err
  make > make.out 2> make.err
  ./main > main.out 2> main.err
  exit $?
fi
