#!/bin/bash

NAME=robots

g++-12 -DEVAL -O2 -o $NAME grader.c $NAME.cpp
