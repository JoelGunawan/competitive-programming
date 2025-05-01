#!/bin/bash

NAME=game

/usr/bin/g++ -std=c++11 -DEVAL -static -O2 -Wall -o $NAME grader.c $NAME.cpp
