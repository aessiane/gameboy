#!/bin/sh
# This script test the emulator with all the roms in a directory

if [ $# -ne 1 ]
then
  echo "Usage: $0 directory"
  exit 1
fi

COUNT=0

for file in $1/*
do
  ./ege "$file" > /tmp/file 2> /tmp/err
  if [ -s /tmp/err ]
  then
    ((COUNT++))
    echo "GAME NAME : $file"
    echo
    cat /tmp/file
    cat /tmp/err
    echo "________________________________________"
  fi
done

echo "Total= "$COUNT
