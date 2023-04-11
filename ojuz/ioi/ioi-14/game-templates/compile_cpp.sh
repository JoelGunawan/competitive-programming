#!/bin/bash

NAME=game

g++-12 -DEVAL -O2 -o $NAME grader.cpp $NAME.cpp
