#!/bin/bash

# Problem name
NAME=persiapan

# Compiler flags
CPP=g++-14
CPPFLAGS="-Wall -O2 -std=c++17"

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

$CPP $CPPFLAGS -o $NAME grader.cpp $NAME.cpp

if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation successful!${NC}"
else
    echo -e "${RED}Compilation failed!${NC}"
fi
