#!/bin/bash

NAME=training

/usr/bin/g++ -o $NAME grader.cpp $NAME.cpp -O2 -lm -std=c++17 