#!/bin/bash

NAME=hari_kebalikan

g++-12 -o $NAME grader.cpp $NAME.cpp -O2 -lm -std=c++11 