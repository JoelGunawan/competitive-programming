#!/bin/bash

NAME=security
/usr/bin/g++ -o $NAME grader.cpp hacker.cpp spy.cpp -O2 -lm -std=c++17