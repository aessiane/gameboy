#!/bin/sh

EXECUTABLE_NAME=`cat CMakeLists.txt  | grep "set.*PROJECT" | sed "s/.*PROJECT\s\+\([A-Za-z0-9_-]*\).*/\\1/g"`
rm -rf build "$EXECUTABLE_NAME"
