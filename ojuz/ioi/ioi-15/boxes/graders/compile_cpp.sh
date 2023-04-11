#!/bin/bash

problem=boxes

g++-12 -O2 -o $problem -Wall -Wshadow -Wextra -Wconversion grader.cpp $problem.cpp
