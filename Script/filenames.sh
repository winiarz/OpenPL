#!/bin/bash

filenames="$1"
prefix="$2"
postfix="$3"

for filename in $filenames
do
  echo "$prefix$filename$postfix"
done
