#!/bin/bash

NAME=wall

g++-12 -DEVAL -O2 -std=c++11 -o $NAME grader.cpp $NAME.cpp
