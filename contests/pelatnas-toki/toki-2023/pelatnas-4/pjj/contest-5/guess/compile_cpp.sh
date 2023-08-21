#!/bin/bash

problem=guess

g++ -std=c++17 -O2 -Wall -pipe -o "${problem}" grader.cpp "${problem}.cpp"
