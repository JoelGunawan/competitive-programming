#!/bin/bash

set NAME=sum

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11