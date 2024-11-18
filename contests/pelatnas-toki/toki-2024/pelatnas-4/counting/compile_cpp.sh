#!/bin/bash

NAME=counting

g++-13 -o $NAME grader.cpp $NAME.cpp -O2 -lm -std=c++11
