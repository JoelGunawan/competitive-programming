#!/bin/bash

problem=paint

g++-12 -O2 -std=c++11 -o $problem grader.cpp $problem.cpp
