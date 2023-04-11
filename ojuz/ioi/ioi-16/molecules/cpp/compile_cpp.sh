#!/bin/bash

problem=molecules

g++-12 -o $problem grader.cpp $problem.cpp
